
int CRYPTO_128_wrap(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,void *param_4,
                   uint param_5,code *param_6)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined auStack_28 [4];
  
  if ((param_5 & 7) == 0) {
    if (param_5 - 8 < 0x7ffffff9) {
      memcpy(param_3 + 2,param_4,param_5);
      iVar3 = 6;
      if (param_2 == (undefined4 *)0x0) {
        param_2 = DAT_000eeb00;
      }
      local_38 = *param_2;
      local_34 = param_2[1];
      uVar4 = 1;
      do {
        uVar5 = (param_5 - 1 >> 3) + 1 + uVar4;
        puVar6 = param_3 + 2;
        do {
          local_30 = *puVar6;
          uStack_2c = puVar6[1];
          (*param_6)(&local_38,&local_38,param_1,auStack_28);
          uVar2 = local_34;
          bVar1 = (byte)uVar4 ^ local_34._3_1_;
          local_34 = CONCAT13(bVar1,(undefined3)local_34);
          if (0xff < uVar4) {
            local_34._2_1_ = SUB41(uVar2,2);
            local_34._1_1_ = SUB41(uVar2,1);
            local_34._0_1_ = (byte)uVar2;
            local_34 = CONCAT31(CONCAT21(CONCAT11(bVar1,local_34._2_1_ ^ (byte)(uVar4 >> 8)),
                                         local_34._1_1_ ^ (byte)(uVar4 >> 0x10)),
                                (byte)local_34 ^ (byte)(uVar4 >> 0x18));
          }
          uVar4 = uVar4 + 1;
          *puVar6 = local_30;
          puVar6[1] = uStack_2c;
          puVar6 = puVar6 + 2;
        } while (uVar4 != uVar5);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar3 = param_5 + 8;
      *param_3 = local_38;
      param_3[1] = local_34;
    }
    else {
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

