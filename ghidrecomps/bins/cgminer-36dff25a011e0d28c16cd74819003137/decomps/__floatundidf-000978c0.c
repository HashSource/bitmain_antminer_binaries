
ulonglong __floatundidf(uint param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  
  if ((param_1 | param_2) == 0) {
    return CONCAT44(param_2,param_1);
  }
  iVar9 = 0x432;
  uVar8 = param_2 >> 0x16;
  if (uVar8 != 0) {
    iVar9 = 3;
    if (param_2 >> 0x19 != 0) {
      iVar9 = 6;
    }
    if (param_2 >> 0x1c != 0) {
      iVar9 = iVar9 + 3;
    }
    iVar9 = iVar9 - ((int)param_2 >> 0x1f);
    uVar8 = param_1 << (0x20U - iVar9 & 0xff);
    param_1 = param_1 >> iVar9 | param_2 << (0x20U - iVar9 & 0xff);
    param_2 = param_2 >> iVar9;
    iVar9 = iVar9 + 0x432;
  }
  if (0xfffff < param_2) {
    if (0x1fffff < param_2) {
      bVar1 = (byte)param_2;
      param_2 = param_2 >> 1;
      bVar2 = (byte)param_1;
      param_1 = (uint)(bVar1 & 1) << 0x1f | param_1 >> 1;
      uVar8 = (uint)(bVar2 & 1) << 0x1f | uVar8 >> 1;
      iVar9 = iVar9 + 1;
      if (0xffbfffff < (uint)(iVar9 * 0x200000)) {
        return 0x7ff0000000000000;
      }
    }
LAB_00097698:
    bVar11 = 0x7fffffff < uVar8;
    if (uVar8 == 0x80000000) {
      bVar11 = (bool)((byte)param_1 & 1);
    }
    return CONCAT44(param_2 + iVar9 * 0x100000 + (uint)CARRY4(param_1,(uint)bVar11),param_1 + bVar11
                   );
  }
  bVar1 = (byte)(uVar8 >> 0x1f);
  uVar8 = uVar8 << 1;
  uVar3 = param_1 * 2;
  bVar11 = CARRY4(param_1,param_1);
  param_1 = param_1 * 2 + (uint)bVar1;
  param_2 = param_2 * 2 + (uint)(bVar11 || CARRY4(uVar3,(uint)bVar1));
  iVar9 = iVar9 + -1;
  if ((param_2 & 0x100000) != 0) goto LAB_00097698;
  uVar3 = param_1;
  uVar4 = param_2;
  if (param_2 == 0) {
    uVar3 = 0;
    uVar4 = param_1;
  }
  iVar6 = LZCOUNT(uVar4);
  if (param_2 == 0) {
    iVar6 = iVar6 + 0x20;
  }
  uVar7 = iVar6 - 0xb;
  bVar12 = SBORROW4(uVar7,0x20);
  uVar5 = iVar6 - 0x2b;
  bVar11 = (int)uVar5 < 0;
  bVar10 = uVar5 == 0;
  if ((int)uVar7 < 0x20) {
    bVar12 = SCARRY4(uVar5,0xc);
    iVar6 = iVar6 + -0x1f;
    bVar11 = iVar6 < 0;
    bVar10 = iVar6 == 0;
    uVar5 = uVar7;
    if (!bVar10 && bVar11 == bVar12) {
      uVar3 = uVar4 << (uVar7 & 0xff);
      uVar4 = uVar4 >> (0xcU - iVar6 & 0xff);
      goto LAB_00097718;
    }
  }
  if (bVar10 || bVar11 != bVar12) {
    uVar8 = 0x20 - uVar5;
  }
  uVar4 = uVar4 << (uVar5 & 0xff);
  if (bVar10 || bVar11 != bVar12) {
    uVar4 = uVar4 | uVar3 >> (uVar8 & 0xff);
    uVar3 = uVar3 << (uVar5 & 0xff);
  }
LAB_00097718:
  if ((int)uVar7 <= iVar9) {
    return CONCAT44(uVar4 + (iVar9 - uVar7) * 0x100000,uVar3);
  }
  uVar8 = ~(iVar9 - uVar7);
  if (0x1e < (int)uVar8) {
    return (ulonglong)(uVar4 >> (uVar8 - 0x1f & 0xff));
  }
  iVar9 = uVar8 - 0x13;
  if (iVar9 == 0 || iVar9 < 0 != SCARRY4(uVar8 - 0x1f,0xc)) {
    uVar8 = uVar8 + 1;
    return CONCAT44(uVar4 >> (uVar8 & 0xff),uVar3 >> (uVar8 & 0xff) | uVar4 << (0x20 - uVar8 & 0xff)
                   );
  }
  return (ulonglong)(uVar3 >> (0x20 - (0xcU - iVar9) & 0xff) | uVar4 << (0xcU - iVar9 & 0xff));
}

