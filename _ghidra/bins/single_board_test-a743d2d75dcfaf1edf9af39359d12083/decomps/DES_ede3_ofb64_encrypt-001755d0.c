
void DES_ede3_ofb64_encrypt
               (uchar *in,uchar *out,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int *num)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint local_4c;
  uint local_48;
  byte local_38 [4];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  uint local_30;
  uint local_2c;
  
  uVar6 = (uint)(*ivec)[3];
  uVar2 = (uint)(*ivec)[7];
  uVar3 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] | uVar6 << 0x18;
  uVar4 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] | uVar2 << 0x18;
  local_48 = uVar3 >> 0x10;
  local_4c = uVar3 >> 8;
  uVar5 = *num;
  uVar10 = uVar4 >> 8;
  uVar9 = uVar4 >> 0x10;
  local_30 = uVar3;
  local_38[0] = (*ivec)[0];
  local_38[1] = (*ivec)[1];
  local_38[2] = (*ivec)[2];
  local_38[3] = (*ivec)[3];
  local_2c = uVar4;
  local_34 = (*ivec)[4];
  local_33 = (*ivec)[5];
  local_32 = (*ivec)[6];
  local_31 = (*ivec)[7];
  if (length != 0) {
    pbVar7 = in + -1;
    iVar8 = 0;
    do {
      if (uVar5 == 0) {
        iVar8 = iVar8 + 1;
        DES_encrypt3(&local_30,ks1,ks2,ks3);
        local_38[0] = (byte)local_30;
        local_4c = local_30 >> 8;
        local_48 = local_30 >> 0x10;
        uVar10 = local_2c >> 8;
        uVar9 = local_2c >> 0x10;
        uVar2 = local_2c >> 0x18;
        uVar6 = local_30 >> 0x18;
        local_38[3] = (byte)(local_30 >> 0x18);
        local_34 = (byte)local_2c;
        local_38[1] = (byte)(local_30 >> 8);
        local_33 = (byte)(local_2c >> 8);
        local_32 = (byte)(local_2c >> 0x10);
        local_38[2] = (byte)(local_30 >> 0x10);
        local_31 = (byte)(local_2c >> 0x18);
        uVar3 = local_30;
        uVar4 = local_2c;
      }
      length = length + -1;
      pbVar7 = pbVar7 + 1;
      pbVar1 = local_38 + uVar5;
      uVar5 = uVar5 + 1 & 7;
      *out = *pbVar1 ^ *pbVar7;
      out = out + 1;
    } while (length != 0);
    if (iVar8 != 0) {
      (*ivec)[0] = (uchar)uVar3;
      (*ivec)[3] = (uchar)uVar6;
      (*ivec)[2] = (uchar)local_48;
      (*ivec)[1] = (uchar)local_4c;
      (*ivec)[4] = (uchar)uVar4;
      (*ivec)[5] = (uchar)uVar10;
      (*ivec)[6] = (uchar)uVar9;
      (*ivec)[7] = (uchar)uVar2;
    }
  }
  *num = uVar5;
  return;
}

