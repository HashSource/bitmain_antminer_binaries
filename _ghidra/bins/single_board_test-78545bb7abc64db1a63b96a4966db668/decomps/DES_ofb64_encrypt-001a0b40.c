
void DES_ofb64_encrypt(uchar *in,uchar *out,long length,DES_key_schedule *schedule,DES_cblock *ivec,
                      int *num)

{
  byte *pbVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  byte local_38 [4];
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  uint local_30;
  undefined4 local_2c;
  
  local_30 = *(uint *)*ivec;
  local_2c = *(undefined4 *)(*ivec + 4);
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
    pbVar3 = out + -1;
    iVar4 = 0;
    do {
      if (uVar2 == 0) {
        iVar4 = iVar4 + 1;
        DES_encrypt1(&local_30,schedule,1);
        local_38[0] = (byte)local_30;
        local_38[1] = (char)(local_30 >> 8);
        local_38[2] = (char)(local_30 >> 0x10);
        local_38[3] = (char)(local_30 >> 0x18);
        local_34 = (char)local_2c;
        local_33 = (char)((uint)local_2c >> 8);
        local_32 = (char)((uint)local_2c >> 0x10);
        local_31 = (char)((uint)local_2c >> 0x18);
      }
      length = length + -1;
      pbVar1 = local_38 + uVar2;
      uVar2 = uVar2 + 1 & 7;
      pbVar3 = pbVar3 + 1;
      *pbVar3 = *pbVar1 ^ *in;
      in = in + 1;
    } while (length != 0);
    if (iVar4 != 0) {
      (*ivec)[0] = (uchar)local_30;
      (*ivec)[1] = (uchar)(local_30 >> 8);
      (*ivec)[2] = (uchar)(local_30 >> 0x10);
      (*ivec)[3] = (uchar)(local_30 >> 0x18);
      (*ivec)[4] = (uchar)local_2c;
      (*ivec)[5] = (uchar)((uint)local_2c >> 8);
      (*ivec)[6] = (uchar)((uint)local_2c >> 0x10);
      (*ivec)[7] = (uchar)((uint)local_2c >> 0x18);
    }
  }
  *num = uVar2;
  return;
}

