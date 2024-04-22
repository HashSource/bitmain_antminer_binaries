
void gost_enc_cfb(undefined4 param_1,undefined4 *param_2,byte *param_3,byte *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  byte local_24;
  byte local_23;
  byte local_22;
  byte local_21;
  
  local_2c = param_2[1];
  local_30 = *param_2;
  if (0 < param_5) {
    iVar6 = 0;
    do {
      iVar6 = iVar6 + 1;
      gostcrypt(param_1,&local_30,&local_28);
      bVar1 = *param_3;
      *param_4 = bVar1 ^ local_28;
      bVar2 = param_3[1];
      param_4[1] = bVar2 ^ local_27;
      bVar3 = param_3[2];
      param_4[2] = bVar3 ^ local_26;
      bVar4 = param_3[3];
      param_4[3] = bVar4 ^ local_25;
      bVar5 = param_3[4];
      local_30 = CONCAT13(bVar4 ^ local_25,
                          CONCAT12(bVar3 ^ local_26,CONCAT11(bVar2 ^ local_27,bVar1 ^ local_28)));
      param_4[4] = bVar5 ^ local_24;
      bVar3 = param_3[5];
      param_4[5] = bVar3 ^ local_23;
      bVar1 = param_3[6];
      param_4[6] = bVar1 ^ local_22;
      bVar2 = param_3[7];
      param_3 = param_3 + 8;
      param_4[7] = bVar2 ^ local_21;
      param_4 = param_4 + 8;
      local_2c = CONCAT13(bVar2 ^ local_21,
                          CONCAT12(bVar1 ^ local_22,CONCAT11(bVar3 ^ local_23,bVar5 ^ local_24)));
    } while (iVar6 != param_5);
  }
  return;
}

