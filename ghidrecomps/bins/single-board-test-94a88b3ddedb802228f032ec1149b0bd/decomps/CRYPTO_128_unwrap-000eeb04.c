
uint CRYPTO_128_unwrap(undefined4 param_1,void *param_2,void *param_3,undefined4 *param_4,
                      int param_5,code *param_6)

{
  byte bVar1;
  undefined4 uVar2;
  void *__s2;
  uint uVar3;
  uint __n;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined auStack_28 [4];
  
  __n = param_5 - 8;
  if ((__n & 7) == 0) {
    if (param_5 - 0x18U < 0x7ffffff1) {
      local_38 = *param_4;
      local_34 = param_4[1];
      uVar5 = (__n >> 3) * 6;
      uVar7 = ~(param_5 - 9U >> 3);
      iVar6 = 6;
      memcpy(param_3,param_4 + 2,__n);
      do {
        if (__n != 0) {
          uVar3 = uVar5;
          puVar4 = (undefined4 *)((int)param_3 + param_5 + -0x10);
          do {
            uVar2 = local_34;
            bVar1 = (byte)uVar3 ^ local_34._3_1_;
            local_34 = CONCAT13(bVar1,(undefined3)local_34);
            if (0xff < uVar3) {
              local_34._2_1_ = SUB41(uVar2,2);
              local_34._1_1_ = SUB41(uVar2,1);
              local_34._0_1_ = (byte)uVar2;
              local_34 = CONCAT31(CONCAT21(CONCAT11(bVar1,local_34._2_1_ ^ (byte)(uVar3 >> 8)),
                                           local_34._1_1_ ^ (byte)(uVar3 >> 0x10)),
                                  (byte)local_34 ^ (byte)(uVar3 >> 0x18));
            }
            local_30 = *puVar4;
            uVar3 = uVar3 - 1;
            uStack_2c = puVar4[1];
            (*param_6)(&local_38,&local_38,param_1,auStack_28);
            *puVar4 = local_30;
            puVar4[1] = uStack_2c;
            puVar4 = puVar4 + -2;
          } while (uVar3 != uVar7 + uVar5);
          uVar5 = uVar5 + uVar7;
        }
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      __s2 = DAT_000eec14;
      if (param_2 != (void *)0x0) {
        __s2 = param_2;
      }
      iVar6 = memcmp(&local_38,__s2,8);
      if (iVar6 != 0) {
        OPENSSL_cleanse(param_3,__n);
        __n = 0;
      }
    }
    else {
      __n = 0;
    }
  }
  else {
    __n = 0;
  }
  return __n;
}

