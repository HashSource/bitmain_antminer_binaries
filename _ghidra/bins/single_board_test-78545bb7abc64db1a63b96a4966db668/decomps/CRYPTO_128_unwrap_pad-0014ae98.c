
uint CRYPTO_128_unwrap_pad
               (undefined4 param_1,void *param_2,undefined4 *param_3,undefined4 param_4,uint param_5
               ,code *param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  
  if ((param_5 & 7) != 0) {
    return 0;
  }
  if (0x7fffffef < param_5 - 0x10) {
    return 0;
  }
  if (param_5 == 0x10) {
    (*param_6)(param_4,&local_30,param_1);
    iVar1 = 8;
    local_38 = local_30;
    local_34 = uStack_2c;
    *param_3 = local_28;
    param_3[1] = uStack_24;
    OPENSSL_cleanse(&local_30,0x10);
  }
  else {
    iVar1 = crypto_128_unwrap_raw(param_1,&local_38,param_3,param_4,param_5,param_6);
    if (param_5 - 8 != iVar1) goto LAB_0014af32;
  }
  if (param_2 == (void *)0x0) {
    iVar2 = CRYPTO_memcmp(&local_38,&default_aiv,4);
  }
  else {
    iVar2 = CRYPTO_memcmp(&local_38,param_2,4);
  }
  if (iVar2 == 0) {
    uVar3 = local_34 << 0x18 | (local_34 >> 8 & 0xff) << 0x10 | (local_34 >> 0x10 & 0xff) << 8 |
            local_34 >> 0x18;
    if (((((param_5 >> 3) + 0x1ffffffe) * 8 < uVar3) && (uVar3 <= ((param_5 >> 3) - 1) * 8)) &&
       (iVar1 = CRYPTO_memcmp((void *)((int)param_3 + uVar3),&zeros_8789,iVar1 - uVar3), iVar1 == 0)
       ) {
      return uVar3;
    }
  }
LAB_0014af32:
  OPENSSL_cleanse(param_3,param_5);
  return 0;
}

