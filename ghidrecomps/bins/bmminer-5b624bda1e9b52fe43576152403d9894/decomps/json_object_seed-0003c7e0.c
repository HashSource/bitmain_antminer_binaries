
/* WARNING: Unknown calling convention */

void json_object_seed(size_t seed)

{
  size_t *psVar1;
  uint32_t new_seed;
  uint32_t seed_1;
  
  psVar1 = DAT_0003c7fc;
  if (*DAT_0003c7fc == 0) {
    if ((seed == 0) && (seed = time((time_t *)0x0), seed == 0)) {
      seed = 1;
    }
    *psVar1 = seed;
  }
  return;
}

