#ifndef GTS_GATE_H__
#define GTS_GATE_H__ 1

#include "algo-gate-api.h"
#include <stdint.h>

#if defined(__AVX2__) && defined(__AES__)
  #define GTS_4WAY
#endif

bool register_gts_algo( algo_gate_t* gate );

#if defined(GTS_4WAY)

void gts_4way_hash( void *state, const void *input );

int scanhash_gts_4way( int thr_id, struct work *work, uint32_t max_nonce,
                       uint64_t *hashes_done );

void init_gts_4way_ctx();

#endif

void gtshash( void *state, const void *input );

int scanhash_gts( int thr_id, struct work *work, uint32_t max_nonce,
                  uint64_t *hashes_done );

void init_gts_ctx();

#endif

