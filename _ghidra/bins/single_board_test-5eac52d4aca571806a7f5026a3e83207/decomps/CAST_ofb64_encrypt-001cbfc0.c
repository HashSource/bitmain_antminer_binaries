
void CAST_ofb64_encrypt(uchar *in,uchar *out,long length,CAST_KEY *schedule,uchar *ivec,int *num)

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
  
  local_30 = (uint)ivec[3] | (uint)ivec[1] << 0x10 | (uint)*ivec << 0x18 | (uint)ivec[2] << 8;
  local_38[3] = ivec[3];
  local_38[1] = ivec[1];
  local_38[0] = *ivec;
  local_38[2] = ivec[2];
  local_33 = ivec[5];
  local_32 = ivec[6];
  local_2c = (uint)ivec[7] | (uint)ivec[5] << 0x10 | (uint)ivec[4] << 0x18 | (uint)ivec[6] << 8;
  local_31 = ivec[7];
  local_34 = ivec[4];
  uVar2 = *num;
  if (length != 0) {
    pbVar4 = out + -1;
    iVar3 = 0;
    do {
      if (uVar2 == 0) {
        CAST_encrypt(&local_30,schedule);
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
      length = length + -1;
      pbVar1 = local_38 + uVar2;
      uVar2 = uVar2 + 1 & 7;
      pbVar4 = pbVar4 + 1;
      *pbVar4 = *pbVar1 ^ *in;
      in = in + 1;
    } while (length != 0);
    if (iVar3 != 0) {
      ivec[3] = (uchar)local_30;
      *ivec = (uchar)(local_30 >> 0x18);
      ivec[1] = (uchar)(local_30 >> 0x10);
      ivec[2] = (uchar)(local_30 >> 8);
      ivec[7] = (uchar)local_2c;
      ivec[4] = (uchar)(local_2c >> 0x18);
      ivec[5] = (uchar)(local_2c >> 0x10);
      ivec[6] = (uchar)(local_2c >> 8);
    }
  }
  *num = uVar2;
  return;
}

