#ifndef ___TIGER_H___
#define ___TIGER_H___

#include "rhsyscfg.h"

typedef struct _tiger_hash_state
{
    ulong64 state[3], length;
    unsigned long curlen;
    unsigned char buf[64];
} tiger_hash_state;

void tiger_init(tiger_hash_state *md);
void tiger_process(tiger_hash_state * md, const unsigned char *buf, unsigned long len);
void tiger_done(tiger_hash_state * md, unsigned char *hash);

static void _tiger_compress(tiger_hash_state *md);

static void _tiger_round(ulong64 *a, ulong64 *b, ulong64 *c, ulong64 x, ulong64 mul);
static void _tiger_pass(ulong64 *a, ulong64 *b, ulong64 *c, ulong64 *x, ulong64 mul);
static void _tiger_key_schedule(ulong64 *x);

#endif // ___TIGER_H___
