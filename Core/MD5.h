#ifndef MD5_H
#define MD5_H

#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

#pragma region MD5 defines

#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

static unsigned char PADDING[64] = {
    0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

#define FF(a, b, c, d, x, s, ac) { \
    (a) += F ((b), (c), (d)) + (x) + (UINT4)(ac); \
    (a) = ROTATE_LEFT ((a), (s)); \
    (a) += (b); \
    }

#define GG(a, b, c, d, x, s, ac) { \
    (a) += G ((b), (c), (d)) + (x) + (UINT4)(ac); \
    (a) = ROTATE_LEFT ((a), (s)); \
    (a) += (b); \
    }

#define HH(a, b, c, d, x, s, ac) { \
    (a) += H ((b), (c), (d)) + (x) + (UINT4)(ac); \
    (a) = ROTATE_LEFT ((a), (s)); \
    (a) += (b); \
    }

#define II(a, b, c, d, x, s, ac) { \
    (a) += I ((b), (c), (d)) + (x) + (UINT4)(ac); \
    (a) = ROTATE_LEFT ((a), (s)); \
    (a) += (b); \
    }

#pragma endregion

typedef unsigned char BYTE ;

typedef unsigned char *POINTER;

typedef unsigned short int UINT2;

typedef unsigned long int UINT4;

class MD5
{
private:
    struct __context_t {
        UINT4 state[4];
        UINT4 count[2];
        unsigned char buffer[64];
    } context ;

    #pragma region static helper functions

    static void MD5Transform(UINT4 state[4], unsigned char block[64])
    {
        UINT4 a = state[0], b = state[1], c = state[2], d = state[3], x[16];

        Decode(x, block, 64);

        FF(a, b, c, d, x[ 0], S11, 0xd76aa478);
        FF(d, a, b, c, x[ 1], S12, 0xe8c7b756);
        FF(c, d, a, b, x[ 2], S13, 0x242070db);
        FF(b, c, d, a, x[ 3], S14, 0xc1bdceee);
        FF(a, b, c, d, x[ 4], S11, 0xf57c0faf);
        FF(d, a, b, c, x[ 5], S12, 0x4787c62a);
        FF(c, d, a, b, x[ 6], S13, 0xa8304613);
        FF(b, c, d, a, x[ 7], S14, 0xfd469501);
        FF(a, b, c, d, x[ 8], S11, 0x698098d8);
        FF(d, a, b, c, x[ 9], S12, 0x8b44f7af);
        FF(c, d, a, b, x[10], S13, 0xffff5bb1);
        FF(b, c, d, a, x[11], S14, 0x895cd7be);
        FF(a, b, c, d, x[12], S11, 0x6b901122);
        FF(d, a, b, c, x[13], S12, 0xfd987193);
        FF(c, d, a, b, x[14], S13, 0xa679438e);
        FF(b, c, d, a, x[15], S14, 0x49b40821);

        GG(a, b, c, d, x[ 1], S21, 0xf61e2562);
        GG(d, a, b, c, x[ 6], S22, 0xc040b340);
        GG(c, d, a, b, x[11], S23, 0x265e5a51);
        GG(b, c, d, a, x[ 0], S24, 0xe9b6c7aa);
        GG(a, b, c, d, x[ 5], S21, 0xd62f105d);
        GG(d, a, b, c, x[10], S22,  0x2441453);
        GG(c, d, a, b, x[15], S23, 0xd8a1e681);
        GG(b, c, d, a, x[ 4], S24, 0xe7d3fbc8);
        GG(a, b, c, d, x[ 9], S21, 0x21e1cde6);
        GG(d, a, b, c, x[14], S22, 0xc33707d6);
        GG(c, d, a, b, x[ 3], S23, 0xf4d50d87);
        GG(b, c, d, a, x[ 8], S24, 0x455a14ed);
        GG(a, b, c, d, x[13], S21, 0xa9e3e905);
        GG(d, a, b, c, x[ 2], S22, 0xfcefa3f8);
        GG(c, d, a, b, x[ 7], S23, 0x676f02d9);
        GG(b, c, d, a, x[12], S24, 0x8d2a4c8a);

        HH(a, b, c, d, x[ 5], S31, 0xfffa3942);
        HH(d, a, b, c, x[ 8], S32, 0x8771f681);
        HH(c, d, a, b, x[11], S33, 0x6d9d6122);
        HH(b, c, d, a, x[14], S34, 0xfde5380c);
        HH(a, b, c, d, x[ 1], S31, 0xa4beea44);
        HH(d, a, b, c, x[ 4], S32, 0x4bdecfa9);
        HH(c, d, a, b, x[ 7], S33, 0xf6bb4b60);
        HH(b, c, d, a, x[10], S34, 0xbebfbc70);
        HH(a, b, c, d, x[13], S31, 0x289b7ec6);
        HH(d, a, b, c, x[ 0], S32, 0xeaa127fa);
        HH(c, d, a, b, x[ 3], S33, 0xd4ef3085);
        HH(b, c, d, a, x[ 6], S34,  0x4881d05);
        HH(a, b, c, d, x[ 9], S31, 0xd9d4d039);
        HH(d, a, b, c, x[12], S32, 0xe6db99e5);
        HH(c, d, a, b, x[15], S33, 0x1fa27cf8);
        HH(b, c, d, a, x[ 2], S34, 0xc4ac5665);

        II(a, b, c, d, x[ 0], S41, 0xf4292244);
        II(d, a, b, c, x[ 7], S42, 0x432aff97);
        II(c, d, a, b, x[14], S43, 0xab9423a7);
        II(b, c, d, a, x[ 5], S44, 0xfc93a039);
        II(a, b, c, d, x[12], S41, 0x655b59c3);
        II(d, a, b, c, x[ 3], S42, 0x8f0ccc92);
        II(c, d, a, b, x[10], S43, 0xffeff47d);
        II(b, c, d, a, x[ 1], S44, 0x85845dd1);
        II(a, b, c, d, x[ 8], S41, 0x6fa87e4f);
        II(d, a, b, c, x[15], S42, 0xfe2ce6e0);
        II(c, d, a, b, x[ 6], S43, 0xa3014314);
        II(b, c, d, a, x[13], S44, 0x4e0811a1);
        II(a, b, c, d, x[ 4], S41, 0xf7537e82);
        II(d, a, b, c, x[11], S42, 0xbd3af235);
        II(c, d, a, b, x[ 2], S43, 0x2ad7d2bb);
        II(b, c, d, a, x[ 9], S44, 0xeb86d391);

        state[0] += a;
        state[1] += b;
        state[2] += c;
        state[3] += d;

        memset((POINTER)x, 0, sizeof(x));
    }

    static void Encode(unsigned char *output, UINT4 *input, unsigned int len)
    {
        unsigned int i, j;

        for (i = 0, j = 0; j < len; i++, j += 4) {
            output[j] = (unsigned char)(input[i] & 0xff);
            output[j + 1] = (unsigned char)((input[i] >> 8) & 0xff);
            output[j + 2] = (unsigned char)((input[i] >> 16) & 0xff);
            output[j + 3] = (unsigned char)((input[i] >> 24) & 0xff);
        }
    }

    static void Decode(UINT4 *output, unsigned char *input, unsigned int len)
    {
        unsigned int i, j;

        for (i = 0, j = 0; j < len; i++, j += 4)
            output[i] = ((UINT4)input[j]) | (((UINT4)input[j + 1]) << 8) |
                (((UINT4)input[j + 2]) << 16) | (((UINT4)input[j + 3]) << 24);
    }
    #pragma endregion


public:
    MD5()
    {
        Init() ;
    }

    void Init()
    {
        context.count[0] = context.count[1] = 0;
        context.state[0] = 0x67452301;
        context.state[1] = 0xefcdab89;
        context.state[2] = 0x98badcfe;
        context.state[3] = 0x10325476;
    }

    void Update(
        unsigned char *input,
        unsigned int inputLen)
    {
        unsigned int i, index, partLen;

        index = (unsigned int)((context.count[0] >> 3) & 0x3F);

        if ((context.count[0] += ((UINT4)inputLen << 3))
            < ((UINT4)inputLen << 3)) {
            context.count[1]++;
        }

        context.count[1] += ((UINT4)inputLen >> 29);

        partLen = 64 - index;

        if (inputLen >= partLen) {
            memcpy((POINTER)&context.buffer[index], (POINTER)input, partLen);
            MD5Transform(context.state, context.buffer);

            for (i = partLen; i + 63 < inputLen; i += 64) {
                MD5Transform(context.state, &input[i]);
            }

            index = 0;
        }
        else {
            i = 0;
        }

        memcpy((POINTER)&context.buffer[index], (POINTER)&input[i], inputLen - i);
    }

    void Final()
    {
        unsigned char bits[8];
        unsigned int index, padLen;

        Encode(bits, context.count, 8);

        index = (unsigned int)((context.count[0] >> 3) & 0x3f);
        padLen = (index < 56) ? (56 - index) : (120 - index);
        Update(PADDING, padLen);

        Update(bits, 8);

        Encode(digestRaw, context.state, 16);

        memset((POINTER)&context, 0, sizeof(context));

        writeToString() ;
    }

    void writeToString()
    {
        int pos ;

        for (pos = 0 ; pos < 16 ; pos++) {
            sprintf(digestChars + (pos * 2), "%02x", digestRaw[pos]) ;
        }
    }


public:
    BYTE digestRaw[ 16 ] ;
    char digestChars[ 33 ] ;

    char* digestFile(char *filename)
    {
        Init() ;
        FILE *file;
        int len;
        unsigned char buffer[1024] ;

        if ((file = fopen(filename, "rb")) == NULL) {
            return 0;
        }
        else
        {
            while (len = fread(buffer, 1, 1024, file)) {
                Update(buffer, len) ;
            }

            Final();
            fclose(file);
        }

        return digestChars ;
    }

    char* digestMemory(BYTE *memchunk, int len)
    {
        Init() ;
        Update(memchunk, len) ;
        Final() ;
        return digestChars ;
    }

    char* digestString(char *string)
    {
        Init() ;
        Update((unsigned char*)string, strlen(string)) ;
        Final() ;
        return digestChars ;
    }
};

#endif