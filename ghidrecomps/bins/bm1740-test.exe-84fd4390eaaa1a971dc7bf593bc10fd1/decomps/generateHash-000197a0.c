
void generateHash(void *param_1,undefined4 param_2,undefined4 param_3,undefined param_4)

{
  undefined auStack_180 [364];
  undefined4 local_14 [2];
  
  local_14[0] = param_2;
  memcpy(auStack_180,param_1,0x168);
  blake2b_update(auStack_180,local_14,4,0);
  blake2b_final(auStack_180,param_3,param_4);
  return;
}

