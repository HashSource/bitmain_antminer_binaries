
void decred_hash_simple(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_84 [124];
  
  sph_blake256_init(auStack_84);
  sph_blake256(auStack_84,param_2,0xb4);
  sph_blake256_close(auStack_84,param_1);
  return;
}

