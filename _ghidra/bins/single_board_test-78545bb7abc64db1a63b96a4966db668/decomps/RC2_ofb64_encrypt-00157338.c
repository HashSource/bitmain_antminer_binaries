
void RC2_ofb64_encrypt(uchar *in,uchar *out,long length,RC2_KEY *schedule,uchar *ivec,int *num)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte local_38 [4];
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  ulong local_30;
  undefined4 local_2c;
  
  local_30 = *(ulong *)ivec;
  local_2c = *(undefined4 *)(ivec + 4);
  local_38[0] = (byte)local_30;
  local_38[2] = (char)(local_30 >> 0x10);
  local_38[3] = (char)(local_30 >> 0x18);
  local_34 = (char)local_2c;
  local_33 = (char)((uint)local_2c >> 8);
  local_31 = (char)((uint)local_2c >> 0x18);
  local_38[1] = (char)(local_30 >> 8);
  local_32 = (char)((uint)local_2c >> 0x10);
  uVar2 = *num;
  if (length != 0) {
    pbVar4 = out + -1;
    iVar3 = 0;
    do {
      if (uVar2 == 0) {
        RC2_encrypt(&local_30,schedule);
        iVar3 = iVar3 + 1;
        local_38[0] = (byte)local_30;
        local_34 = (char)local_2c;
        local_38[1] = (char)(local_30 >> 8);
        local_38[2] = (char)(local_30 >> 0x10);
        local_38[3] = (char)(local_30 >> 0x18);
        local_33 = (char)((uint)local_2c >> 8);
        local_32 = (char)((uint)local_2c >> 0x10);
        local_31 = (char)((uint)local_2c >> 0x18);
      }
      length = length + -1;
      pbVar1 = local_38 + uVar2;
      uVar2 = uVar2 + 1 & 7;
      pbVar4 = pbVar4 + 1;
      *pbVar4 = *pbVar1 ^ *in;
      in = in + 1;
    } while (length != 0);
    if (iVar3 != 0) {
      *ivec = (uchar)local_30;
      ivec[1] = (uchar)(local_30 >> 8);
      ivec[2] = (uchar)(local_30 >> 0x10);
      ivec[3] = (uchar)(local_30 >> 0x18);
      ivec[4] = (uchar)local_2c;
      ivec[5] = (uchar)((uint)local_2c >> 8);
      ivec[6] = (uchar)((uint)local_2c >> 0x10);
      ivec[7] = (uchar)((uint)local_2c >> 0x18);
    }
  }
  *num = uVar2;
  return;
}

