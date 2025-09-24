
void IDEA_ofb64_encrypt(byte *param_1,int param_2,int param_3,undefined4 param_4,byte *param_5,
                       uint *param_6)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte local_38 [4];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  uint local_30;
  uint local_2c;
  
  local_30 = (uint)param_5[3] | (uint)param_5[1] << 0x10 | (uint)*param_5 << 0x18 |
             (uint)param_5[2] << 8;
  local_38[3] = param_5[3];
  local_38[1] = param_5[1];
  local_38[0] = *param_5;
  local_38[2] = param_5[2];
  local_33 = param_5[5];
  local_32 = param_5[6];
  local_2c = (uint)param_5[7] | (uint)param_5[5] << 0x10 | (uint)param_5[4] << 0x18 |
             (uint)param_5[6] << 8;
  local_31 = param_5[7];
  local_34 = param_5[4];
  uVar2 = *param_6;
  if (param_3 != 0) {
    pbVar4 = (byte *)(param_2 + -1);
    iVar3 = 0;
    do {
      if (uVar2 == 0) {
        IDEA_encrypt(&local_30,param_4);
        iVar3 = iVar3 + 1;
        local_38[3] = (byte)local_30;
        local_31 = (byte)local_2c;
        local_38[0] = (byte)(local_30 >> 0x18);
        local_38[1] = (byte)(local_30 >> 0x10);
        local_38[2] = (byte)(local_30 >> 8);
        local_34 = (byte)(local_2c >> 0x18);
        local_33 = (byte)(local_2c >> 0x10);
        local_32 = (byte)(local_2c >> 8);
      }
      param_3 = param_3 + -1;
      pbVar1 = local_38 + uVar2;
      uVar2 = uVar2 + 1 & 7;
      pbVar4 = pbVar4 + 1;
      *pbVar4 = *pbVar1 ^ *param_1;
      param_1 = param_1 + 1;
    } while (param_3 != 0);
    if (iVar3 != 0) {
      param_5[3] = (byte)local_30;
      *param_5 = (byte)(local_30 >> 0x18);
      param_5[1] = (byte)(local_30 >> 0x10);
      param_5[2] = (byte)(local_30 >> 8);
      param_5[7] = (byte)local_2c;
      param_5[4] = (byte)(local_2c >> 0x18);
      param_5[5] = (byte)(local_2c >> 0x10);
      param_5[6] = (byte)(local_2c >> 8);
    }
  }
  *param_6 = uVar2;
  return;
}

