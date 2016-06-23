#pragma once

//#pragma warning( push, 3 )
# include <windows.h>
# include <wincrypt.h>
# include <exception>
//#pragma warning( pop )

#ifndef byte
typedef unsigned char byte;
#endif

#if defined(__cplusplus)
extern "C" {
#endif

	// Vanilla exception class
	class WinAESException : public std::exception
	{
	public:
		WinAESException( const char* message )
			: exception( message ) { };
	};

	class WinAES
	{
	public:
		enum Parameters { KEYSIZE_128 = 16, KEYSIZE_192 = 24, KEYSIZE_256 = 32, BLOCKSIZE = 16 };
		enum Flags { CREATE_CONTAINER = 1, DELETE_CONTAINER = 8, THROW_EXCEPTION = 16,
			DEFAULT_FLAGS = CREATE_CONTAINER | DELETE_CONTAINER };
	public:
		explicit WinAES( const wchar_t* lpszContainer=NULL, int nFlags=DEFAULT_FLAGS );
		explicit WinAES( HCRYPTPROV hProvider );

		virtual ~WinAES( );

		// Generate a random block of bytes using the underlying CSP.
		bool GenerateRandom( byte* buffer, int size );

		// Sets the Key and IV. The key must be of size KEYSIZE_128, KEYSIZE_192,
		//  or KEYSIZE_256. The IV must be of size BLOCKSIZE.
		bool SetKeyWithIv( const byte* key, int ksize, const byte* iv, int vsize=BLOCKSIZE );

		// Sets the Key. The key must be of size KEYSIZE_128,
		// KEYSIZE_192, or KEYSIZE_256. After calling SetKey,
		// for intial keying or re-keying, call SetIv.
		bool SetKey( const byte* key, int ksize = KEYSIZE_128 );

		// Sets the IV. The IV must be of size BLOCKSIZE. Call
		//  anytime to syncronize the IV under a key.
		bool SetIv(const byte* iv, int vsize=BLOCKSIZE );

		// Returns the maximum size of the ciphertext, which includes
		// padding for the plaintext.
		bool MaxCipherTextSize( size_t psize, size_t& csize );

		// Returns the maximum size of the plaintext, which includes
		// removal of padding on the plaintext.
		bool MaxPlainTextSize( size_t csize, size_t& psize );

		// Encrpyt a buffer in-place. bsize is the size of the buffer,
		//  psize is the size of the plaintext. If successful,
		//  csize is the size of the ciphertext. On entry, bsize >= csize.
		bool Encrypt( /*InOut*/byte* buffer, /*In*/size_t bsize, /*In*/size_t psize, /*Out*/ size_t& csize );

		// Decrpyt a buffer in-place. bsize is the size of the buffer,
		//  csize is the size of the ciphertext. If successful,
		//  psize is the size of the recovered plaintext.
		//  On entry, bsize >= psize.
		bool Decrypt( /*InOut*/byte* buffer, /*In*/size_t bsize, /*In*/size_t csize, /*Out*/ size_t& psize );

		// Encrypt plaintext. psize is the size of the plaintext.
		//  If successful, csize is the size of the ciphertext.
		bool Encrypt( /*In*/const byte* plaintext, /*In*/size_t psize, /*InOut*/byte* ciphertext, /*InOut*/ size_t& csize );

		// Decrypt plaintext. csize is the size of the ciphertext.
		//  If successful, psize is the size of the plaintext.
		bool Decrypt( /*In*/const byte* ciphertext, /*In*/size_t csize, /*InOut*/byte* plaintext, /*InOut*/ size_t& psize );

		// Duplicate a context. The caller is responsible for a call to
		//  CryptReleaseContext
		HCRYPTPROV DuplicateContext();

		// Convenience - Converts the value of GetLastError to a
		//  #define for easy web searching. No use to users.
		static const char* ErrorToDefine( DWORD dwError );

	protected:
		bool AcquireContext( const wchar_t* lpszContainer );

		// Protected inner class
	protected:
		typedef struct _AesKey
		{
			BLOBHEADER Header;
			DWORD dwKeyLength;
			//BYTE cbKey[ANYSIZE_ARRAY];
			// Set to max possible key size
			BYTE cbKey[KEYSIZE_256];

			_AesKey() {
				ZeroMemory( this, sizeof(_AesKey) );
				Header.bType = PLAINTEXTKEYBLOB;
				Header.bVersion = CUR_BLOB_VERSION;
				Header.reserved = 0;
			}

#pragma optimize( "", off )
			// No dead code removal. Key material must be scrubbed
			~_AesKey() {                
				SecureZeroMemory( this, sizeof(this) );
			}
			// Restore previous optimizations
#pragma optimize( "", on )

		} AesKey;

		// No copying
	private:
		WinAES( WinAES& ) { };

		// Private data
	private:
		HCRYPTPROV m_hProvider;
		HCRYPTKEY m_hAesKey;
		wchar_t* m_wszContainer;
		bool m_bHaveIv;
		int m_nFlags;

		// Used to destroy a temporary keyset
		enum { INVALID_INDEX = -1 };
		int m_nIndex;
	};

	typedef struct PROV_PARAMS_T
	{
		const WCHAR* lpwsz;
		DWORD dwType;
		DWORD dwFlags;
	} PROV_PARAMS, PPROV_PARAMS;

	typedef struct PROVIDERS_T {
		PROV_PARAMS params;
	} PROVIDERS, PPROVIDERS;

	// To get an AES provider, we *cannot* use the Base, Strong, or Enhanced
	//  providers since AES is not available.
	// http://msdn.microsoft.com/en-us/library/aa375599(VS.85).aspx
	// http://msdn.microsoft.com/en-us/library/aa382020(VS.85).aspx
	const PROVIDERS AesProviders[] = 
	{
		// http://msdn.microsoft.com/en-us/library/aa375545(VS.85).aspx
		{ reinterpret_cast<CONST WCHAR*>(MS_ENH_RSA_AES_PROV_W), PROV_RSA_AES, 0 },
		{ reinterpret_cast<CONST WCHAR*>(MS_ENH_RSA_AES_PROV_W), PROV_RSA_AES, CRYPT_NEWKEYSET },
		{ reinterpret_cast<CONST WCHAR*>(MS_ENH_RSA_AES_PROV_XP_W), PROV_RSA_AES, 0 },
		{ reinterpret_cast<CONST WCHAR*>(MS_ENH_RSA_AES_PROV_XP_W), PROV_RSA_AES, CRYPT_NEWKEYSET },
	};

#if defined(__cplusplus)
}
#endif