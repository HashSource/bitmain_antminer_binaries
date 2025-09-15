
ulonglong __extendsfdf2(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint in_r12;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  uVar3 = param_1 << 1;
  bVar9 = uVar3 == 0;
  uVar1 = param_1 & 0x80000000;
  uVar5 = (uint)((int)uVar3 >> 3) >> 1;
  uVar2 = uVar1 | uVar5;
  param_1 = param_1 << 0x1d;
  if (!bVar9) {
    param_4 = uVar3 & 0xff000000;
    bVar9 = param_4 == 0;
  }
  if (!bVar9) {
    bVar9 = param_4 == 0xff000000;
  }
  if (!bVar9) {
    return CONCAT44(uVar2,param_1) ^ 0x3800000000000000;
  }
  if ((uVar3 & 0xffffff) == 0) {
    return CONCAT44(uVar2,param_1);
  }
  if (param_4 == 0xff000000) {
    return CONCAT44(uVar2,param_1) | 0x8000000000000;
  }
  uVar3 = param_1;
  uVar4 = uVar5;
  if (uVar5 == 0) {
    uVar3 = 0;
    uVar4 = param_1;
  }
  iVar6 = LZCOUNT(uVar4);
  if (uVar5 == 0) {
    iVar6 = iVar6 + 0x20;
  }
  uVar7 = iVar6 - 0xb;
  bVar10 = SBORROW4(uVar7,0x20);
  uVar5 = iVar6 - 0x2b;
  bVar9 = (int)uVar5 < 0;
  bVar8 = uVar5 == 0;
  if ((int)uVar7 < 0x20) {
    bVar10 = SCARRY4(uVar5,0xc);
    iVar6 = iVar6 + -0x1f;
    bVar9 = iVar6 < 0;
    bVar8 = iVar6 == 0;
    uVar5 = uVar7;
    if (!bVar8 && bVar9 == bVar10) {
      uVar3 = uVar4 << (uVar7 & 0xff);
      uVar4 = uVar4 >> (0xcU - iVar6 & 0xff);
      goto LAB_00097718;
    }
  }
  if (bVar8 || bVar9 != bVar10) {
    in_r12 = 0x20 - uVar5;
  }
  uVar4 = uVar4 << (uVar5 & 0xff);
  if (bVar8 || bVar9 != bVar10) {
    uVar4 = uVar4 | uVar3 >> (in_r12 & 0xff);
    uVar3 = uVar3 << (uVar5 & 0xff);
  }
LAB_00097718:
  if ((int)uVar7 < 0x381) {
    return CONCAT44(uVar4 + (0x380 - uVar7) * 0x100000 | uVar1,uVar3);
  }
  uVar5 = ~(0x380 - uVar7);
  if (0x1e < (int)uVar5) {
    return CONCAT44(uVar2,uVar4 >> (uVar5 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  iVar6 = uVar5 - 0x13;
  if (iVar6 == 0 || iVar6 < 0 != SCARRY4(uVar5 - 0x1f,0xc)) {
    uVar5 = uVar5 + 1;
    return CONCAT44(uVar1 | uVar4 >> (uVar5 & 0xff),
                    uVar3 >> (uVar5 & 0xff) | uVar4 << (0x20 - uVar5 & 0xff));
  }
  return CONCAT44(uVar2,uVar3 >> (0x20 - (0xcU - iVar6) & 0xff) | uVar4 << (0xcU - iVar6 & 0xff)) &
         0x80000000ffffffff;
}

