
void DES_ede3_ofb64_encrypt
               (uchar *in,uchar *out,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int *num)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_44;
  byte local_38 [4];
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  uint local_30;
  uint local_2c;
  
  uVar11 = *(uint *)*ivec;
  uVar2 = *(uint *)(*ivec + 4);
  local_30 = uVar11;
  uVar3 = uVar11 >> 8;
  uVar9 = uVar11 >> 0x10;
  uVar8 = uVar11 >> 0x18;
  uVar6 = uVar2 >> 8;
  uVar7 = uVar2 >> 0x10;
  uVar10 = uVar2 >> 0x18;
  local_38[0] = (byte)uVar11;
  local_38[1] = (char)(uVar11 >> 8);
  local_38[2] = (char)(uVar11 >> 0x10);
  local_38[3] = (char)(uVar11 >> 0x18);
  local_2c = uVar2;
  local_34 = (char)uVar2;
  local_33 = (char)(uVar2 >> 8);
  local_32 = (char)(uVar2 >> 0x10);
  local_31 = (char)(uVar2 >> 0x18);
  uVar4 = *num;
  if (length != 0) {
    pbVar5 = out + -1;
    local_44 = 0;
    do {
      if (uVar4 == 0) {
        DES_encrypt3(&local_30,ks1,ks2,ks3);
        local_38[0] = (byte)local_30;
        uVar3 = local_30 >> 8;
        uVar9 = local_30 >> 0x10;
        uVar8 = local_30 >> 0x18;
        uVar6 = local_2c >> 8;
        uVar7 = local_2c >> 0x10;
        uVar10 = local_2c >> 0x18;
        local_38[1] = (char)(local_30 >> 8);
        local_44 = local_44 + 1;
        local_38[2] = (char)(local_30 >> 0x10);
        local_38[3] = (char)(local_30 >> 0x18);
        local_34 = (char)local_2c;
        local_33 = (char)(local_2c >> 8);
        local_32 = (char)(local_2c >> 0x10);
        local_31 = (char)(local_2c >> 0x18);
        uVar2 = local_2c;
        uVar11 = local_30;
      }
      length = length + -1;
      pbVar1 = local_38 + uVar4;
      uVar4 = uVar4 + 1 & 7;
      pbVar5 = pbVar5 + 1;
      *pbVar5 = *pbVar1 ^ *in;
      in = in + 1;
    } while (length != 0);
    if (local_44 != 0) {
      (*ivec)[0] = (uchar)uVar11;
      (*ivec)[1] = (uchar)uVar3;
      (*ivec)[2] = (uchar)uVar9;
      (*ivec)[3] = (uchar)uVar8;
      (*ivec)[4] = (uchar)uVar2;
      (*ivec)[5] = (uchar)uVar6;
      (*ivec)[6] = (uchar)uVar7;
      (*ivec)[7] = (uchar)uVar10;
    }
  }
  *num = uVar4;
  return;
}

