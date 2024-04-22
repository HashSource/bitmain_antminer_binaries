
void RC2_ofb64_encrypt(uchar *in,uchar *out,long length,RC2_KEY *schedule,uchar *ivec,int *num)

{
  byte *pbVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  byte local_38 [4];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  uint local_30;
  uint local_2c;
  
  uVar2 = *num;
  local_30 = (uint)ivec[2] << 0x10 | (uint)ivec[1] << 8 | (uint)*ivec | (uint)ivec[3] << 0x18;
  local_38[0] = *ivec;
  local_38[1] = ivec[1];
  local_38[2] = ivec[2];
  local_38[3] = ivec[3];
  local_2c = (uint)ivec[6] << 0x10 | (uint)ivec[5] << 8 | (uint)ivec[4] | (uint)ivec[7] << 0x18;
  local_34 = ivec[4];
  local_33 = ivec[5];
  local_32 = ivec[6];
  local_31 = ivec[7];
  if (length != 0) {
    pbVar3 = in + -1;
    iVar4 = 0;
    do {
      if (uVar2 == 0) {
        RC2_encrypt(&local_30,schedule);
        iVar4 = iVar4 + 1;
        local_38[0] = (byte)local_30;
        local_38[1] = (byte)(local_30 >> 8);
        local_38[2] = (byte)(local_30 >> 0x10);
        local_38[3] = (byte)(local_30 >> 0x18);
        local_34 = (byte)local_2c;
        local_33 = (byte)(local_2c >> 8);
        local_32 = (byte)(local_2c >> 0x10);
        local_31 = (byte)(local_2c >> 0x18);
      }
      length = length + -1;
      pbVar3 = pbVar3 + 1;
      pbVar1 = local_38 + uVar2;
      uVar2 = uVar2 + 1 & 7;
      *out = *pbVar1 ^ *pbVar3;
      out = out + 1;
    } while (length != 0);
    if (iVar4 != 0) {
      *ivec = (uchar)local_30;
      ivec[1] = (uchar)(local_30 >> 8);
      ivec[2] = (uchar)(local_30 >> 0x10);
      ivec[3] = (uchar)(local_30 >> 0x18);
      ivec[4] = (uchar)local_2c;
      ivec[5] = (uchar)(local_2c >> 8);
      ivec[6] = (uchar)(local_2c >> 0x10);
      ivec[7] = (uchar)(local_2c >> 0x18);
    }
  }
  *num = uVar2;
  return;
}

