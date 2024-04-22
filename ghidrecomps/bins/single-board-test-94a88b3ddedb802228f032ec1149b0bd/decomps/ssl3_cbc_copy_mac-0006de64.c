
void ssl3_cbc_copy_mac(int param_1,int param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint extraout_r1;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte *__s;
  int iVar10;
  int iVar11;
  int iVar12;
  byte abStack_a8 [132];
  
  iVar11 = *(int *)(param_2 + 4);
  iVar12 = iVar11 - param_3;
  if (param_4 < param_3) {
    OpenSSLDie(DAT_0006df6c,0xf8,DAT_0006df70);
  }
  if (0x40 < param_3) {
    OpenSSLDie(DAT_0006df6c,0xf9,DAT_0006df74);
  }
  __s = abStack_a8 + (-(int)abStack_a8 & 0x3f);
  if (param_3 + 0x100 < param_4) {
    uVar8 = (param_4 - param_3) - 0x100;
  }
  else {
    uVar8 = 0;
  }
  __aeabi_uidivmod((iVar12 + (param_3 >> 1) * 0x1000000) - uVar8,param_3);
  memset(__s,0,param_3);
  if (uVar8 < param_4) {
    iVar7 = *(int *)(param_2 + 0xc);
    uVar6 = 0;
    do {
      iVar5 = uVar8 - iVar12;
      bVar3 = (byte)(uVar8 >> 0x18);
      bVar4 = (byte)((uint)iVar12 >> 0x18);
      pbVar1 = (byte *)(iVar7 + uVar8);
      iVar10 = uVar8 - iVar11;
      bVar2 = (byte)((uint)iVar11 >> 0x18);
      uVar9 = uVar6 + 1;
      uVar8 = uVar8 + 1;
      __s[uVar6] = *pbVar1 & ~((char)(((byte)((uint)iVar5 >> 0x18) ^ bVar4 | bVar3 ^ bVar4) ^ bVar3)
                              >> 7) &
                   (char)(((byte)((uint)iVar10 >> 0x18) ^ bVar2 | bVar3 ^ bVar2) ^ bVar3) >> 7 |
                   __s[uVar6];
      uVar6 = uVar9 & (int)((uVar9 - param_3 ^ param_3 | uVar9 ^ param_3) ^ uVar9) >> 0x1f;
    } while (uVar8 != param_4);
  }
  if (param_3 != 0) {
    uVar6 = 0;
    uVar8 = extraout_r1;
    do {
      uVar9 = uVar8 + 1;
      *(byte *)(param_1 + uVar6) = __s[uVar8];
      uVar6 = uVar6 + 1;
      uVar8 = uVar9 & (int)((uVar9 - param_3 ^ param_3 | uVar9 ^ param_3) ^ uVar9) >> 0x1f;
    } while (uVar6 != param_3);
  }
  return;
}

