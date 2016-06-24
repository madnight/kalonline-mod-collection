/*
 * (C) 2016 Fabian Beuke <mail@beuke.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
 


#include "WinAES.h"
#include <sstream>
#include "assert.h"

using std::ostringstream;

WinAES::WinAES( const wchar_t* lpszContainer, int nFlags )
	: m_hProvider(NULL), m_hAesKey(NULL), m_bHaveIv(false),
	m_nFlags(nFlags), m_wszContainer(NULL), m_nIndex(INVALID_INDEX)
{
	if( NULL == lpszContainer ) {
		lpszContainer = L"Temporary - OK to Delete";
		m_nFlags |= DELETE_CONTAINER;
	}

	size_t len = wcslen( lpszContainer ) + 1;
	assert( 0 != len );

	if( len ) {
		m_wszContainer = new wchar_t[ len ];
		assert( NULL != m_wszContainer );

		errno_t err = 0;
		err = wcscpy_s( m_wszContainer, len, lpszContainer );
		assert( 0 == err );
	}

	bool b = AcquireContext( m_wszContainer );
	assert( true == b );
}

WinAES::WinAES( HCRYPTPROV hProvider )
	: m_hProvider(hProvider), m_hAesKey(NULL), m_bHaveIv(false),
	m_nFlags(DEFAULT_FLAGS), m_wszContainer(NULL), m_nIndex(INVALID_INDEX) { }

WinAES::~WinAES( )
{
	// Destroy the key
	if( NULL != m_hAesKey ) {
		CryptDestroyKey( m_hAesKey );
		m_hAesKey = NULL;
	}

	// Destroy the provider
	if( NULL != m_hProvider ) {
		CryptReleaseContext( m_hProvider, 0 );
		m_hProvider = NULL;
	}

	// Destroy the conatiner
	if( DELETE_CONTAINER & m_nFlags )
	{
		if( INVALID_INDEX != m_nIndex )
		{       
			// MSDN: When CRYPT_DELETEKEYSET flag is set, the value returned in phProv
			// is undefined, and thus, the CryptReleaseContext function need not be
			// called afterward.
			CryptAcquireContextW( &m_hProvider, m_wszContainer, AesProviders[m_nIndex].params.lpwsz,
				AesProviders[m_nIndex].params.dwType, CRYPT_DELETEKEYSET );
		}
		m_hProvider = NULL;
	}
	m_nIndex = INVALID_INDEX;

	// Free
	if( NULL != m_wszContainer ) {
		delete[] m_wszContainer;
		m_wszContainer = NULL;
	}
}

bool WinAES::GenerateRandom( byte* buffer, int size )
{
	assert( NULL != buffer );
	assert( size >= 0 );

#ifdef _DEBUG
	// Test the pointer (it is purported good). Not safe for Release builds
	assert( FALSE == IsBadWritePtr( buffer, size ) );
#endif

	assert( NULL != m_hProvider );

	// Convert big BOOL to little bool
	return !!CryptGenRandom( m_hProvider, size, buffer );
}

bool WinAES::AcquireContext( const wchar_t* lpszContainer )
{
	// We need to record the index of the provider which we were able to 
	// acquire in case the use wants to delete the imported key. The
	// class destructor will use the index to delete the proper container.

	for( int i = 0; i < _countof(AesProviders); i++ )
	{
		// Only create a new container if requested
		if( (AesProviders[i].params.dwFlags & CRYPT_NEWKEYSET) &&
			!(m_nFlags & CREATE_CONTAINER ) ) { continue; }

		if( CryptAcquireContextW( &m_hProvider, lpszContainer, AesProviders[i].params.lpwsz,
			AesProviders[i].params.dwType, AesProviders[i].params.dwFlags ) ) {
				m_nIndex = i;
				break;
		}
	}

	// m_nIndex != INVALID_INDEX indicates success. No need for an
	//  extra variable to track success from CryptAcquireContext.
	if( (m_nIndex == INVALID_INDEX) && (THROW_EXCEPTION & m_nFlags) ) {
		throw WinAESException("AcquireContext: CryptAcquireContext failed");
	}

	return m_nIndex != INVALID_INDEX;
}

HCRYPTPROV WinAES::DuplicateContext()
{
	assert( NULL != m_hProvider );
	if( NULL == m_hProvider ) { return NULL; }

	if( CryptContextAddRef( m_hProvider, NULL, 0 ) )
	{ return m_hProvider; }

	assert( false );
	return NULL;
}

bool WinAES::SetKeyWithIv( const byte* key, int ksize, const byte* iv, int vsize )
{
#ifdef _DEBUG
	assert( FALSE == IsBadReadPtr( key, ksize ) );
	assert( FALSE == IsBadReadPtr( iv, vsize ) );
#endif

	// Returned to caller (if non-throwing)
	bool result = true;

	// Is someone is re-keying, we need to release the old key here...
	if( NULL != m_hAesKey ) {
		// Non-fatal
		CryptDestroyKey( m_hAesKey );
		m_hAesKey  = NULL;
		m_bHaveIv = false;
	}

	try
	{
		assert( NULL != m_hProvider );
		if( NULL == m_hProvider ) {
			throw WinAESException( "SetKeyWithIv: Provider is not valid" );
		}

		assert( NULL != key );
		if( NULL == key ) {
			throw WinAESException( "SetKeyWithIv: Key buffer is not valid" );
		}

		assert( ksize == KEYSIZE_128 || ksize == KEYSIZE_192 || ksize == KEYSIZE_256 );
		if( !(ksize == KEYSIZE_128 || ksize == KEYSIZE_192 || ksize == KEYSIZE_256) ) {
			throw WinAESException( "SetKeyWithIv: Key size is not valid" );
		}

		assert( NULL != iv );
		if( NULL == iv ) {
			throw WinAESException( "SetKeyWithIv: IV buffer is not valid" );
		}

		assert( BLOCKSIZE == vsize );
		if( BLOCKSIZE != vsize ) {
			throw WinAESException( "SetKeyWithIv: IV size is not valid" );
		}

		result &= SetKey( key, ksize );
		assert( true == result );
		if( !result ) {
			throw WinAESException("SetKeyWithIv: SetKey failed");
		}

		result &= SetIv( iv, vsize );
		assert( true == result );
		if( !result ) {
			throw WinAESException("SetKeyWithIv: SetIv failed");
		}
	}
	catch( const WinAESException& /*e*/ )
	{
		if(THROW_EXCEPTION & m_nFlags) {
			throw;
		}

		result = false;
	}

	return result;
}

// Sets the Key. The key must be of size KEYSIZE_128,
// KEYSIZE_192 or KEYSIZE_256.
bool WinAES::SetKey( const byte* key, int ksize )
{
#ifdef _DEBUG
	assert( FALSE == IsBadReadPtr( key, ksize ) );
#endif

	// Returned to caller (if non-throwing)
	bool result = false;

	// Is someone is re-keying, we need to release the old key here...
	if( NULL != m_hAesKey ) {
		// Non-fatal
		CryptDestroyKey( m_hAesKey );
		m_hAesKey  = NULL;
		m_bHaveIv = false;
	}

	try
	{
		assert( NULL != m_hProvider );
		if( NULL == m_hProvider ) {
			throw WinAESException( "SetKey: Provider is not valid" );
		}

		assert( NULL != key );
		if( NULL == key ) {
			throw WinAESException( "SetKey: Key buffer is NULL" );
		}

		assert( ksize == KEYSIZE_128 || ksize == KEYSIZE_192 || ksize == KEYSIZE_256 );
		if( !(ksize == KEYSIZE_128 || ksize == KEYSIZE_192 || ksize == KEYSIZE_256) ) {
			throw WinAESException( "SetKey: Key size is not valid" );
		}

		AesKey aeskey;

		switch( ksize )
		{
		case KEYSIZE_128:
			aeskey.Header.aiKeyAlg = CALG_AES_128;
			aeskey.dwKeyLength = KEYSIZE_128;
			break;
		case KEYSIZE_192:
			aeskey.Header.aiKeyAlg = CALG_AES_192;
			aeskey.dwKeyLength = KEYSIZE_192;
			break;
		case KEYSIZE_256:
			aeskey.Header.aiKeyAlg = CALG_AES_256;
			aeskey.dwKeyLength = KEYSIZE_256;
			break;
		default:
			assert( false );
			throw WinAESException("SetKey: Key size is not valid");
		}

		errno_t err = 0;
		err = memcpy_s( aeskey.cbKey, aeskey.dwKeyLength, key, ksize );
		assert( 0 == err );
		if( 0 != err ) {
			throw WinAESException( "SetKey: Unable to copy key" );
		}

		// When the key is imported, the size of the AesKey structure should be exact.
		//  We declared aeskey.cbKey[ KEYSIZE_256 ] to allow a stack allocation.
		//  There are enough bytes available for AES 128, 192, and 256. We do the
		//  proper book keeping now.
		const unsigned structsize = sizeof(AesKey) - KEYSIZE_256 + ksize;

		// Import AES key
		if(!CryptImportKey(m_hProvider, (CONST BYTE*)&aeskey, structsize, NULL, 0, &m_hAesKey ) ) {
			assert( false );
			throw WinAESException("SetKey: Import key failed");
		}

		// Set Mode
		DWORD dwMode = CRYPT_MODE_CBC;
		if(!CryptSetKeyParam(m_hAesKey, KP_MODE, (BYTE*)&dwMode, 0)) {
			assert( false );
			throw WinAESException("SetKey: Set CBC mode failed");
		}

		result = true;
	}
	catch( const WinAESException& /*e*/ )
	{
		if( THROW_EXCEPTION & m_nFlags ) {
			throw;
		}
		result = false;
	}

	return result;
}

// Sets the IV. The IV must be of size BLOCKSIZE.
bool WinAES::SetIv(const byte* iv, int vsize )
{
#ifdef _DEBUG
	assert( FALSE == IsBadReadPtr( iv, vsize ) );
#endif

	// Returned to caller (if non-throwing)
	bool result = false;

	try
	{
		assert( NULL != m_hAesKey );
		if( NULL == m_hAesKey ) {
			throw WinAESException( "SetIv: key is not valid" );
		}

		assert( NULL != iv );
		if( NULL == iv ) {
			throw WinAESException( "SetIv: IV buffer is NULL" );
		}

		assert( BLOCKSIZE == vsize );
		if( BLOCKSIZE != vsize ) {
			throw WinAESException( "SetIv: IV block size is not valid" );
		}

		assert( NULL != m_hAesKey );
		if( NULL == m_hAesKey ) {
			throw WinAESException( "SetIv: Key is not valid" );
		}

		if(!CryptSetKeyParam(m_hAesKey, KP_IV, (BYTE*)iv, 0)) {
			throw WinAESException( "SetIv: Set IV failed" );
		}

		// Set Mode
		DWORD dwMode = CRYPT_MODE_CBC;
		if(!CryptSetKeyParam(m_hAesKey, KP_MODE, (BYTE*)&dwMode, 0)) {
			assert( false );
			throw WinAESException("SetIv: Set CBC mode failed");
		}

		result = m_bHaveIv = true;
	}
	catch( const WinAESException& /*e*/ )
	{
		result = m_bHaveIv = false;

		if( THROW_EXCEPTION & m_nFlags ) {
			throw;
		}
	}

	return result;
}

// Returns the maximum size of the ciphertext, which includes
// padding for the plaintext
bool WinAES::MaxCipherTextSize( size_t psize, size_t& csize )
{
	size_t blocks = psize / BLOCKSIZE + 1;

	csize = blocks * BLOCKSIZE;
	return true;
}

// Returns the maximum size of the plaintext, which includes
// removal of padding on the plaintext
bool WinAES::MaxPlainTextSize( size_t csize, size_t& psize )
{
	assert( 0 == csize % BLOCKSIZE );
	if( 0 != csize % BLOCKSIZE ) return false;

	// More correctly, csize-1
	psize = csize;
	return true;
}

// Encrpyt a buffer in-place. bsize is the size of the buffer,
//  psize is the size of the plaintext. If successful,
//  csize is the size of the ciphertext. On entry, bsize >= csize.
bool WinAES::Encrypt( byte* buffer, /*In*/size_t bsize, /*In*/size_t psize, /*Out*/ size_t& csize )
{
#ifdef _DEBUG
	// Test the pointer (it is purported good). Not safe for Release builds
	assert( FALSE == IsBadWritePtr( buffer, (DWORD)bsize ) );
#endif

	// Returned to caller (if non-throwing)
	BOOL result = FALSE;

	try
	{
		// sanity check
		assert( NULL != m_hAesKey );
		if( NULL == m_hAesKey ) {
			SetLastError( (DWORD)NTE_BAD_KEY );
			throw WinAESException( "Encrypt(1): Key is not valid" );
		}

		// sanity check
		assert( NULL != buffer );
		if( NULL == buffer ) {
			SetLastError( ERROR_INVALID_USER_BUFFER );
			throw WinAESException( "Encrypt(1): Buffer is NULL" );
		}

		// sanity check
		size_t s = 0;
		if( MaxCipherTextSize( psize, s ) && bsize < s ) {
			assert( false );
			SetLastError( (DWORD)NTE_BUFFER_TOO_SMALL );
			throw WinAESException( "Encrypt(1): Buffer is too small" );
		}

		// sanity check
		assert( true == m_bHaveIv );
		if( false == m_bHaveIv ) {
			SetLastError( (DWORD)NTE_INVALID_PARAMETER );
			throw WinAESException( "Encrypt(1): IV has not been set" );
		}

		// temporary for API
		DWORD d = (DWORD)psize;
		result = CryptEncrypt( m_hAesKey, NULL, TRUE, 0, buffer, &d, (DWORD)bsize );
		assert( TRUE == result );
		if( FALSE == result ) {          
			// Build a useful message
			ostringstream emessage;
			emessage << "Encrypt(1): CryptEncrypt failed - " ;
			emessage << ErrorToDefine( GetLastError() );
			emessage << " (0x" << std::hex << GetLastError() << ")";

			csize = 0;
			throw WinAESException( emessage.str().c_str() );
		}

		// result is TRUE
		csize = d;
	}
	catch( const WinAESException& /*e*/ )
	{
		if( m_nFlags & THROW_EXCEPTION ) {
			throw;
		}
		result = FALSE;
	}

	// Convert the big BOOL to little bool
	return !!result;
}

// Decrpyt a buffer in-place. bsize is the size of the buffer,
//  csize is the size of the ciphertext. If successful,
//  psize is the size of the recovered plaintext.
//  On entry, bsize > psize (always the case since csize <= bsize).
bool WinAES::Decrypt( byte* buffer, /*In*/size_t bsize, /*In*/size_t csize, /*Out*/ size_t& psize )
{
#ifdef _DEBUG
	// Test the pointer (it is purported good). Not safe for Release builds
	assert( FALSE == IsBadWritePtr( buffer, (DWORD)bsize ) );
#endif

	// Returned to caller (if non-throwing)
	BOOL result = FALSE;

	try
	{
		// sanity check
		assert( NULL != m_hAesKey );
		if( NULL == m_hAesKey ) {
			SetLastError( (DWORD)NTE_BAD_KEY );
			throw WinAESException( "Decrypt(1): Key is not valid" );
		}

		// sanity check
		assert( NULL != buffer );
		if( NULL == buffer ) {
			SetLastError( ERROR_INVALID_USER_BUFFER );
			throw WinAESException( "Decrypt(1): Buffer is NULL" );
		}

		// sanity check
		assert( 0 == csize % BLOCKSIZE );
		if( !(0 == csize % BLOCKSIZE) ) {
			SetLastError( (DWORD)NTE_BAD_DATA );
			throw WinAESException( "Decrypt(1): Data size is not a multple of block size" );
		}

		// sanity check
		size_t s = 0;
		if( MaxPlainTextSize( csize, s ) && !(bsize > s-BLOCKSIZE) ) {
			assert( false );
			SetLastError( (DWORD)NTE_BUFFER_TOO_SMALL );
			throw WinAESException( "Decrypt(1): Buffer is too small" );
		}

		// sanity check
		assert( true == m_bHaveIv );
		if( false == m_bHaveIv ) {
			SetLastError( (DWORD)NTE_INVALID_PARAMETER );
			throw WinAESException( "Decrypt(1): IV has not been set" );
		}

		// Temporary for API
		DWORD d = (DWORD)csize;
		result = CryptDecrypt( m_hAesKey, NULL, TRUE, 0, buffer, &d );
		assert( TRUE == result );
		if( FALSE == result ) {
			// Build a useful message
			ostringstream emessage;
			emessage << "Decrypt(1): CryptDecrypt failed - " ;
			emessage << ErrorToDefine( GetLastError() );
			emessage << " (0x" << std::hex << GetLastError() << ")";

			psize = 0;
			throw WinAESException( emessage.str().c_str() );
		}

		// result is TRUE
		psize = d;
	}
	catch( const WinAESException& /*e*/ )
	{
		if( m_nFlags & THROW_EXCEPTION ) {
			throw;
		}
		result = FALSE;
	}

	// Convert the big BOOL to little bool
	return !!result;
}

// Encrypt plaintext. psize is the size of the plaintext.
//  If successful, csize is the size of the ciphertext.
bool WinAES::Encrypt( const byte* plaintext, /*In*/size_t psize, /*InOut*/byte* ciphertext, /*InOut*/ size_t& csize )
{

#ifdef _DEBUG
	// Test the pointer (it is purported good). Not safe for Release builds
	assert( FALSE == IsBadReadPtr( plaintext, psize ));
	assert( FALSE == IsBadWritePtr( ciphertext, csize ));
#endif

	// Returned to caller (if non-throwing)
	bool result = false;

	try
	{
		// sanity check
		assert( plaintext != NULL || ( plaintext == NULL && 0 == psize ) );
		if( !(plaintext != NULL || ( plaintext == NULL && 0 == psize )) ) {
			SetLastError( ERROR_INVALID_USER_BUFFER );
			throw WinAESException( "Encrypt(2): Plain text buffer is not valid" );
		}

		// sanity check
		assert( NULL != ciphertext );
		if( NULL == ciphertext ) {
			SetLastError( ERROR_INVALID_USER_BUFFER );
			throw WinAESException( "Encrypt(2): Cipher text buffer is not valid" );
		}

		// Buffers cannot overlap
		assert( ((size_t)ciphertext+csize < (size_t)plaintext) ||
			((size_t)plaintext+psize < (size_t)ciphertext) );
		if( !(((size_t)ciphertext+csize < (size_t)plaintext) ||
			((size_t)plaintext+psize < (size_t)ciphertext) ) )
		{
			SetLastError( (DWORD)NTE_BUFFERS_OVERLAP );
			throw WinAESException( "Encrypt(2): Buffers overlap" );
		}

		errno_t err = memcpy_s( ciphertext, csize, plaintext, psize );
		assert( 0 == err );
		if( 0 != err ) {
			throw WinAESException( "Encrypt(2): Unable to prepare plaintext buffer" );
		}

		result = Encrypt( ciphertext, csize, psize, csize );
		assert( true == result );
		if( FALSE == result ) {
			// Build a useful message
			ostringstream emessage;
			emessage << "Encrypt(2): Encryption failed - " ;
			emessage << ErrorToDefine( GetLastError() );
			emessage << " (0x" << std::hex << GetLastError() << ")";

			csize = 0;
			throw WinAESException( emessage.str().c_str() );
		}

		// result is TRUE
	}

	catch( const WinAESException& /*e*/ )
	{
		if( m_nFlags & THROW_EXCEPTION ) {
			throw;
		}
		result = false;
	}

	return result;
}

// Decrypt plaintext. csize is the size of the ciphertext.
//  If successful, psize is the size of the plaintext.
bool WinAES::Decrypt( const byte* ciphertext, /*In*/size_t csize, /*InOut*/byte* plaintext, /*InOut*/ size_t& psize )
{

#ifdef _DEBUG
	// Test the pointer (it is purported good). Not safe for Release builds
	assert( FALSE == IsBadReadPtr( ciphertext, csize ));
	assert( FALSE == IsBadWritePtr( plaintext, psize ));
#endif

	// Returned to caller
	bool result = false;

	try
	{
		// sanity check
		assert( NULL != ciphertext );
		assert( NULL != plaintext );
		if( NULL == ciphertext || NULL == plaintext ) {
			SetLastError( ERROR_INVALID_USER_BUFFER );
			throw WinAESException( "Decrypt(2): Buffer is NULL" );
		}

		// Buffers cannot overlap
		assert( ((size_t)ciphertext+csize < (size_t)plaintext) ||
			((size_t)plaintext+psize < (size_t)ciphertext) );
		if( !(((size_t)ciphertext+csize < (size_t)plaintext) ||
			((size_t)plaintext+psize < (size_t)ciphertext) ) )
		{
			SetLastError( (DWORD)NTE_BUFFERS_OVERLAP );
			throw WinAESException( "Decrypt(2): Buffers overlap" );
		}

		errno_t err = memcpy_s( plaintext, psize, ciphertext, csize );
		assert( 0 == err );
		if( 0 != err ) {
			throw WinAESException( "Decrypt(2): Unable to prepare decryption buffer" );
		}

		result = Decrypt( plaintext, csize, csize, psize );
		assert( true == result );
		if( false == result ) {
			// Build a useful message
			ostringstream emessage;
			emessage << "Decrypt(2): Decryption failed - " ;
			emessage << ErrorToDefine( GetLastError() );
			emessage << " (0x" << std::hex << GetLastError() << ")";

			psize = 0;
			throw WinAESException( emessage.str().c_str() );
		}

		// result is TRUE
	}

	catch( const WinAESException& /*e*/ )
	{
		if( m_nFlags & THROW_EXCEPTION ) {
			throw;
		}
		result = false;
	}

	return result;
}

const char* WinAES::ErrorToDefine( DWORD dwError )
{
	switch( dwError )
	{
	case ERROR_ACCESS_DENIED:
		return "ERROR_ACCESS_DENIED";  
	case ERROR_INVALID_HANDLE:
		return "ERROR_INVALID_HANDLE";  
	case ERROR_INVALID_PARAMETER:
		return "ERROR_INVALID_PARAMETER";
	case ERROR_DEV_NOT_EXIST:
		return "ERROR_DEV_NOT_EXIST";
	case NTE_BAD_HASH:
		return "NTE_BAD_HASH";        
	case NTE_BAD_HASH_STATE:
		return "NTE_BAD_HASH_STATE";
	case NTE_BAD_UID:
		return "NTE_BAD_UID";
	case NTE_BAD_KEY:
		return "NTE_BAD_KEY";
	case NTE_BAD_LEN:
		return "NTE_BAD_LEN";
	case NTE_BAD_DATA:
		return "NTE_BAD_DATA";
	case NTE_BAD_VER:
		return "NTE_BAD_VER";
	case NTE_BAD_ALGID:
		return "NTE_BAD_ALGID";
	case NTE_BAD_FLAGS:
		return "NTE_BAD_FLAGS";
	case NTE_BAD_TYPE:
		return "NTE_BAD_TYPE";
	case NTE_BAD_KEY_STATE:
		return "NTE_BAD_KEY_STATE";
	case NTE_NO_KEY:
		return "NTE_NO_KEY";
	case NTE_NO_MEMORY:
		return "NTE_NO_MEMORY";
	case NTE_EXISTS:
		return "NTE_EXISTS";
	case NTE_PERM:
		return "NTE_PERM";
	case NTE_NOT_FOUND:
		return "NTE_NOT_FOUND";
	case NTE_DOUBLE_ENCRYPT:
		return "NTE_DOUBLE_ENCRYPT";
	case NTE_BAD_PROVIDER:
		return "NTE_BAD_PROVIDER";
	case NTE_BAD_PROV_TYPE:
		return "NTE_BAD_PROV_TYPE";
	case NTE_BAD_KEYSET:
		return "NTE_BAD_KEYSET";
	case NTE_PROV_TYPE_NOT_DEF:
		return "NTE_PROV_TYPE_NOT_DEF";
	case NTE_PROV_TYPE_ENTRY_BAD:
		return "NTE_PROV_TYPE_ENTRY_BAD";
	case NTE_KEYSET_NOT_DEF:
		return "NTE_KEYSET_NOT_DEF";
	case NTE_KEYSET_ENTRY_BAD:
		return "NTE_KEYSET_ENTRY_BAD";
	case NTE_BAD_KEYSET_PARAM:
		return "NTE_BAD_KEYSET_PARAM";
	case NTE_FAIL:
		return "NTE_FAIL";
	case NTE_SYS_ERR:
		return "NTE_SYS_ERR";
	case NTE_SILENT_CONTEXT:
		return "NTE_SILENT_CONTEXT";
	case NTE_FIXEDPARAMETER:
		return "NTE_FIXEDPARAMETER";
	case NTE_INVALID_HANDLE:
		return "NTE_INVALID_HANDLE";
	case NTE_INVALID_PARAMETER:
		return "NTE_INVALID_PARAMETER";
	case NTE_BUFFER_TOO_SMALL:
		return "NTE_BUFFER_TOO_SMALL";
	case NTE_BUFFERS_OVERLAP:
		return "NTE_BUFFERS_OVERLAP";
	case NTE_DECRYPTION_FAILURE:
		return "NTE_DECRYPTION_FAILURE";
	case NTE_INTERNAL_ERROR:
		return "NTE_INTERNAL_ERROR";
	default: ;
	}

	return "Unknown";
}