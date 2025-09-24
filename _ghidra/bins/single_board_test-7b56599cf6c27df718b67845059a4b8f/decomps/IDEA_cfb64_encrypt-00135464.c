
void IDEA_cfb64_encrypt(byte *param_1,byte *param_2,int param_3,undefined4 param_4,byte *param_5,
                       uint *param_6,int param_7)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint local_30;
  uint local_2c;
  
  uVar3 = *param_6;
  if (param_7 == 0) {
    if (param_3 != 0) {
      do {
        if (uVar3 == 0) {
          local_30 = (uint)param_5[1] << 0x10 | (uint)*param_5 << 0x18 | (uint)param_5[3] |
                     (uint)param_5[2] << 8;
          local_2c = (uint)param_5[5] << 0x10 | (uint)param_5[4] << 0x18 | (uint)param_5[7] |
                     (uint)param_5[6] << 8;
          IDEA_encrypt(&local_30,param_4);
          param_5[3] = (byte)local_30;
          param_5[7] = (byte)local_2c;
          *param_5 = (byte)(local_30 >> 0x18);
          param_5[1] = (byte)(local_30 >> 0x10);
          param_5[2] = (byte)(local_30 >> 8);
          param_5[4] = (byte)(local_2c >> 0x18);
          param_5[5] = (byte)(local_2c >> 0x10);
          param_5[6] = (byte)(local_2c >> 8);
        }
        bVar1 = param_5[uVar3];
        param_3 = param_3 + -1;
        bVar2 = *param_1;
        param_5[uVar3] = bVar2;
        uVar3 = uVar3 + 1 & 7;
        *param_2 = bVar1 ^ bVar2;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      } while (param_3 != 0);
    }
  }
  else if (param_3 != 0) {
    do {
      if (uVar3 == 0) {
        local_30 = (uint)param_5[1] << 0x10 | (uint)*param_5 << 0x18 | (uint)param_5[3] |
                   (uint)param_5[2] << 8;
        local_2c = (uint)param_5[5] << 0x10 | (uint)param_5[4] << 0x18 | (uint)param_5[7] |
                   (uint)param_5[6] << 8;
        IDEA_encrypt(&local_30,param_4);
        param_5[3] = (byte)local_30;
        param_5[7] = (byte)local_2c;
        *param_5 = (byte)(local_30 >> 0x18);
        param_5[1] = (byte)(local_30 >> 0x10);
        param_5[2] = (byte)(local_30 >> 8);
        param_5[4] = (byte)(local_2c >> 0x18);
        param_5[5] = (byte)(local_2c >> 0x10);
        param_5[6] = (byte)(local_2c >> 8);
      }
      bVar1 = param_5[uVar3];
      param_3 = param_3 + -1;
      bVar2 = *param_1;
      *param_2 = bVar1 ^ bVar2;
      param_5[uVar3] = bVar1 ^ bVar2;
      uVar3 = uVar3 + 1 & 7;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (param_3 != 0);
  }
  *param_6 = uVar3;
  return;
}

