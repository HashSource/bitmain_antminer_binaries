
int CRYPTO_128_wrap(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,void *param_4,
                   uint param_5,code *param_6)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  
  if (((param_5 & 7) == 0) && (param_5 - 0x10 < 0x7ffffff1)) {
    memmove(param_3 + 2,param_4,param_5);
    if (param_2 == (undefined4 *)0x0) {
      param_2 = &default_iv;
    }
    local_38 = *param_2;
    iVar6 = 6;
    local_34 = param_2[1];
    uVar3 = 1;
    do {
      uVar5 = (param_5 - 1 >> 3) + 1 + uVar3;
      puVar4 = param_3 + 2;
      do {
        local_30 = *puVar4;
        uStack_2c = puVar4[1];
        (*param_6)(&local_38,&local_38,param_1,auStack_28);
        uVar2 = local_34;
        bVar1 = local_34._3_1_ ^ (byte)uVar3;
        local_34 = CONCAT13(bVar1,(undefined3)local_34);
        if (0xff < uVar3) {
          local_34._2_1_ = SUB41(uVar2,2);
          local_34._1_1_ = SUB41(uVar2,1);
          local_34._0_1_ = (byte)uVar2;
          local_34 = CONCAT31(CONCAT21(CONCAT11(bVar1,local_34._2_1_ ^ (byte)(uVar3 >> 8)),
                                       local_34._1_1_ ^ (byte)(uVar3 >> 0x10)),
                              (byte)local_34 ^ (byte)(uVar3 >> 0x18));
        }
        uVar3 = uVar3 + 1;
        *puVar4 = local_30;
        puVar4[1] = uStack_2c;
        puVar4 = puVar4 + 2;
      } while (uVar5 != uVar3);
      iVar6 = iVar6 + -1;
      uVar3 = uVar5;
    } while (iVar6 != 0);
    *param_3 = local_38;
    param_3[1] = local_34;
    return param_5 + 8;
  }
  return 0;
}

