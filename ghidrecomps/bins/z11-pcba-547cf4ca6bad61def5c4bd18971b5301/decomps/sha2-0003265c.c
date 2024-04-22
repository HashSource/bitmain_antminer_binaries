
void sha2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_f0 [232];
  
  sha2_starts(auStack_f0);
  sha2_update(auStack_f0,param_1,param_2);
  sha2_finish(auStack_f0,param_3);
  memset(auStack_f0,0,0xe8);
  return;
}

