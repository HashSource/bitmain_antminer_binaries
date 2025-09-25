
undefined4
CRYPTO_128_wrap_pad(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,void *param_4,
                   size_t param_5,code *param_6)

{
  uint uVar1;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar1 = param_5 + 7 & 0xfffffff8;
  if ((int)param_5 < 1) {
    param_1 = 0;
  }
  if (0 < (int)param_5) {
    if (param_2 == (undefined4 *)0x0) {
      local_20 = 0xa65959a6;
    }
    else {
      local_20 = *param_2;
    }
    local_1c._3_1_ = (undefined1)param_5;
    local_1c._0_3_ =
         CONCAT12((char)(param_5 >> 8),CONCAT11((char)(param_5 >> 0x10),(char)(param_5 >> 0x18)));
    if (uVar1 == 8) {
      memmove(param_3 + 2,param_4,param_5);
      *param_3 = local_20;
      param_3[1] = local_1c;
      memset((void *)((int)param_3 + param_5 + 8),0,uVar1 - param_5);
      (*param_6)(param_3,param_3,param_1);
      return 0x10;
    }
    memmove(param_3,param_4,param_5);
    memset((void *)((int)param_3 + param_5),0,uVar1 - param_5);
    param_1 = CRYPTO_128_wrap(param_1,&local_20,param_3,param_3,uVar1,param_6);
  }
  return param_1;
}

