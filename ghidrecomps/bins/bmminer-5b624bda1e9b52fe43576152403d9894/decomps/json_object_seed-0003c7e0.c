
/* WARNING: Unknown calling convention */

void json_object_seed(size_t seed)

{
  uint32_t uVar1;
  
  uVar1 = hashtable_seed;
  if (((hashtable_seed == 0) && (uVar1 = seed, seed == 0)) &&
     (uVar1 = time((time_t *)0x0), uVar1 == 0)) {
    uVar1 = 1;
  }
  hashtable_seed = uVar1;
  return;
}

