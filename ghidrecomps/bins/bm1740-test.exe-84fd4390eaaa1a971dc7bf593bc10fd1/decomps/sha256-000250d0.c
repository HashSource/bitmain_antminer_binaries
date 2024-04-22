
void sha256(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_b0 [168];
  
  sha256_init(auStack_b0);
  sha256_update(auStack_b0,param_1,param_2);
  sha256_final(auStack_b0,param_3);
  return;
}

