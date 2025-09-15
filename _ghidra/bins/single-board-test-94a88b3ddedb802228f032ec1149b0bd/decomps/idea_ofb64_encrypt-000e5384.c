
void idea_ofb64_encrypt(uchar *in,uchar *out,long length,IDEA_KEY_SCHEDULE *ks,uchar *iv,int *num)

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
  local_30 = (uint)iv[1] << 0x10 | (uint)*iv << 0x18 | (uint)iv[3] | (uint)iv[2] << 8;
  local_38[3] = iv[3];
  local_38[0] = *iv;
  local_38[1] = iv[1];
  local_38[2] = iv[2];
  local_2c = (uint)iv[5] << 0x10 | (uint)iv[4] << 0x18 | (uint)iv[7] | (uint)iv[6] << 8;
  local_31 = iv[7];
  local_34 = iv[4];
  local_33 = iv[5];
  local_32 = iv[6];
  if (length != 0) {
    pbVar3 = in + -1;
    iVar4 = 0;
    do {
      if (uVar2 == 0) {
        idea_encrypt(&local_30,ks);
        iVar4 = iVar4 + 1;
        local_38[3] = (byte)local_30;
        local_38[0] = (byte)(local_30 >> 0x18);
        local_38[1] = (byte)(local_30 >> 0x10);
        local_38[2] = (byte)(local_30 >> 8);
        local_31 = (byte)local_2c;
        local_34 = (byte)(local_2c >> 0x18);
        local_33 = (byte)(local_2c >> 0x10);
        local_32 = (byte)(local_2c >> 8);
      }
      length = length + -1;
      pbVar3 = pbVar3 + 1;
      pbVar1 = local_38 + uVar2;
      uVar2 = uVar2 + 1 & 7;
      *out = *pbVar1 ^ *pbVar3;
      out = out + 1;
    } while (length != 0);
    if (iVar4 != 0) {
      iv[3] = (uchar)local_30;
      *iv = (uchar)(local_30 >> 0x18);
      iv[1] = (uchar)(local_30 >> 0x10);
      iv[2] = (uchar)(local_30 >> 8);
      iv[7] = (uchar)local_2c;
      iv[4] = (uchar)(local_2c >> 0x18);
      iv[5] = (uchar)(local_2c >> 0x10);
      iv[6] = (uchar)(local_2c >> 8);
    }
  }
  *num = uVar2;
  return;
}

