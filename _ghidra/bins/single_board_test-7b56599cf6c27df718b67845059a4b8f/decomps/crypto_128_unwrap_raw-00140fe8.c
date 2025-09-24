
uint crypto_128_unwrap_raw
               (undefined4 param_1,undefined4 *param_2,void *param_3,undefined4 *param_4,int param_5
               ,code *param_6)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint __n;
  undefined4 *puVar5;
  uint uVar6;
  int local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  
  __n = param_5 - 8;
  if (((__n & 7) == 0) && (param_5 - 0x18U < 0x7ffffff1)) {
    local_38 = *param_4;
    local_34 = param_4[1];
    local_48 = 6;
    memmove(param_3,param_4 + 2,__n);
    uVar6 = (__n >> 3) * 6;
    uVar3 = ~(param_5 - 9U >> 3);
    do {
      if (__n != 0) {
        uVar4 = uVar6;
        puVar5 = (undefined4 *)((int)param_3 + param_5 + -0x10);
        do {
          uVar2 = local_34;
          bVar1 = local_34._3_1_ ^ (byte)uVar4;
          local_34 = CONCAT13(bVar1,(undefined3)local_34);
          if (0xff < uVar4) {
            local_34._2_1_ = SUB41(uVar2,2);
            local_34._1_1_ = SUB41(uVar2,1);
            local_34._0_1_ = (byte)uVar2;
            local_34 = CONCAT31(CONCAT21(CONCAT11(bVar1,local_34._2_1_ ^ (byte)(uVar4 >> 8)),
                                         local_34._1_1_ ^ (byte)(uVar4 >> 0x10)),
                                (byte)local_34 ^ (byte)(uVar4 >> 0x18));
          }
          local_30 = *puVar5;
          uVar4 = uVar4 - 1;
          uStack_2c = puVar5[1];
          (*param_6)(&local_38,&local_38,param_1,auStack_28);
          *puVar5 = local_30;
          puVar5[1] = uStack_2c;
          puVar5 = puVar5 + -2;
        } while (uVar4 != uVar3 + uVar6);
        uVar6 = uVar6 + uVar3;
      }
      local_48 = local_48 + -1;
    } while (local_48 != 0);
    *param_2 = local_38;
    param_2[1] = local_34;
    return __n;
  }
  return 0;
}

