
void gost_dec_cfb(undefined4 param_1,undefined4 *param_2,byte *param_3,byte *param_4,int param_5)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
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
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 1;
      gostcrypt(param_1,&local_30,&local_28);
      bVar2 = *param_3;
      *param_4 = bVar2 ^ local_28;
      bVar3 = param_3[1];
      param_4[1] = bVar3 ^ local_27;
      bVar4 = param_3[2];
      param_4[2] = bVar4 ^ local_26;
      local_30 = CONCAT13(param_3[3],CONCAT12(bVar4,CONCAT11(bVar3,bVar2)));
      param_4[3] = param_3[3] ^ local_25;
      bVar2 = param_3[4];
      param_4[4] = bVar2 ^ local_24;
      bVar3 = param_3[5];
      param_4[5] = bVar3 ^ local_23;
      bVar4 = param_3[6];
      param_4[6] = bVar4 ^ local_22;
      pbVar1 = param_3 + 7;
      param_3 = param_3 + 8;
      local_2c = CONCAT13(*pbVar1,CONCAT12(bVar4,CONCAT11(bVar3,bVar2)));
      param_4[7] = *pbVar1 ^ local_21;
      param_4 = param_4 + 8;
    } while (iVar5 != param_5);
  }
  return;
}

