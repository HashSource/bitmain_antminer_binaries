
void blake2b_hash(undefined4 *param_1,undefined4 param_2)

{
  undefined auStack_140 [256];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  blake2b_init(auStack_140,0x20,0,0);
  blake2b_update(auStack_140,param_2,0x50);
  blake2b_final(auStack_140,&local_40);
  *param_1 = local_40;
  param_1[1] = uStack_3c;
  param_1[2] = uStack_38;
  param_1[3] = uStack_34;
  param_1[4] = local_30;
  param_1[5] = uStack_2c;
  param_1[6] = uStack_28;
  param_1[7] = uStack_24;
  return;
}

