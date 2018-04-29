#include "gts-gate.h"

bool register_gts_algo( algo_gate_t* gate )
{
#if defined (GTS_4WAY)
  init_gts_4way_ctx();
  gate->scanhash  = (void*)&scanhash_gts_4way;
  gate->hash      = (void*)&gts_4way_hash;
#else
  init_gts_ctx();
  gate->scanhash  = (void*)&scanhash_gts;
  gate->hash      = (void*)&gtshash;
#endif
  gate->optimizations = SSE2_OPT | AES_OPT | AVX_OPT | AVX2_OPT;
  return true;
};

