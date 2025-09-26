
undefined4 ssl3_cbc_copy_mac(byte *param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint unaff_r6;
  byte *__s;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  byte abStack_a8 [132];
  
  uVar9 = *(uint *)(param_2 + 0xc);
  bVar13 = 0x3f < param_3;
  bVar12 = param_3 == 0x40;
  if (param_3 < 0x41) {
    bVar13 = uVar9 <= param_3;
    bVar12 = param_3 == uVar9;
  }
  if (bVar13 && !bVar12) {
    uVar5 = 0;
  }
  else {
    if (uVar9 <= param_3 + 0x100) {
      unaff_r6 = 0;
    }
    __s = abStack_a8 + (-(int)abStack_a8 & 0x3f);
    if (param_3 + 0x100 < uVar9) {
      unaff_r6 = (uVar9 - 0x100) - param_3;
    }
    uVar8 = *(uint *)(param_2 + 8);
    memset(__s,0,param_3);
    if (unaff_r6 < uVar9) {
      uVar6 = 0;
      uVar4 = 0;
      uVar10 = 0;
      pbVar2 = (byte *)(*(int *)(param_2 + 0x14) + unaff_r6);
      do {
        uVar11 = uVar8 - param_3 ^ unaff_r6;
        uVar7 = (uVar8 ^ unaff_r6 | unaff_r6 - uVar8 ^ uVar8) ^ unaff_r6;
        unaff_r6 = unaff_r6 + 1;
        uVar11 = (int)(uVar11 - 1 & ~uVar11) >> 0x1f;
        uVar10 = (uVar11 | uVar10) & (int)uVar7 >> 0x1f;
        uVar7 = uVar4 + 1;
        uVar6 = uVar6 | uVar11 & uVar4;
        __s[uVar4] = __s[uVar4] | *pbVar2 & (byte)uVar10;
        uVar4 = uVar7 & (int)((uVar7 - param_3 ^ param_3 | param_3 ^ uVar7) ^ uVar7) >> 0x1f;
        pbVar2 = pbVar2 + 1;
      } while (uVar9 != unaff_r6);
    }
    else {
      uVar6 = 0;
    }
    if (param_3 != 0) {
      pbVar2 = param_1;
      do {
        uVar8 = uVar6 & 0xffffffdf;
        uVar9 = uVar6 | 0x20;
        uVar4 = uVar8 ^ uVar6;
        uVar6 = uVar6 + 1;
        bVar1 = (char)((byte)(uVar4 - 1 >> 0x18) & ~(byte)(uVar4 >> 0x18)) >> 7;
        uVar6 = uVar6 & (int)((uVar6 - param_3 ^ param_3 | param_3 ^ uVar6) ^ uVar6) >> 0x1f;
        pbVar3 = pbVar2 + 1;
        *pbVar2 = ~bVar1 & __s[uVar9] | __s[uVar8] & bVar1;
        pbVar2 = pbVar3;
      } while (param_1 + param_3 != pbVar3);
    }
    uVar5 = 1;
  }
  return uVar5;
}

