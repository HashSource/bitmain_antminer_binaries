
ulonglong __subdf3(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  
  uVar8 = param_4 ^ 0x80000000;
  uVar11 = param_2 << 1;
  param_4 = param_4 << 1;
  bVar14 = uVar11 == param_4 && param_1 == param_3;
  if (uVar11 != param_4 || param_1 != param_3) {
    bVar14 = (uVar11 | param_1) == 0;
  }
  if (!bVar14) {
    bVar14 = (param_4 | param_3) == 0;
  }
  iVar10 = (int)uVar11 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar10 == -1;
  }
  iVar1 = (int)param_4 >> 0x15;
  if (!bVar14) {
    bVar14 = iVar1 == -1;
  }
  if (bVar14) {
    if (iVar10 == -1 || iVar1 == -1) {
      uVar11 = uVar8;
      uVar12 = param_3;
      if (iVar10 == -1) {
        uVar11 = param_2;
        uVar12 = param_1;
      }
      if (iVar10 != -1 || iVar1 != -1) {
        param_3 = uVar12;
        uVar8 = uVar11;
      }
      bVar14 = (uVar12 | uVar11 << 0xc) == 0;
      if (bVar14) {
        bVar14 = (param_3 | uVar8 << 0xc) == 0;
      }
      if (bVar14) {
        bVar14 = uVar11 == uVar8;
      }
      if (!bVar14) {
        uVar11 = uVar11 | 0x80000;
      }
      return CONCAT44(uVar11,uVar12);
    }
    if (uVar11 != param_4 || param_1 != param_3) {
      if ((uVar11 | param_1) == 0) {
        param_1 = param_3;
        param_2 = uVar8;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != uVar8) {
      return 0;
    }
    if (uVar11 >> 0x15 == 0) {
      bVar3 = (byte)(param_1 >> 0x1f);
      uVar11 = param_2 * 2 + (uint)bVar3;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar3)) {
        uVar11 = uVar11 | 0x80000000;
      }
      return CONCAT44(uVar11,param_1 << 1);
    }
    if (uVar11 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_000977f0:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar11 = uVar11 >> 0x15;
  param_4 = param_4 >> 0x15;
  uVar12 = param_4 - uVar11;
  bVar14 = uVar12 != 0;
  if (param_4 < uVar11) {
    uVar12 = -uVar12;
  }
  uVar7 = param_1;
  uVar9 = param_2;
  if (bVar14 && uVar11 <= param_4) {
    uVar11 = uVar11 + uVar12;
    uVar7 = param_3;
    uVar9 = uVar8;
    param_3 = param_1;
    uVar8 = param_2;
  }
  if (0x36 < uVar12) {
    return CONCAT44(uVar9,uVar7);
  }
  uVar6 = uVar9 & 0xfffff | 0x100000;
  if ((uVar9 & 0x80000000) != 0) {
    bVar14 = uVar7 != 0;
    uVar7 = -uVar7;
    uVar6 = -(uVar6 + bVar14);
  }
  uVar9 = uVar8 & 0xfffff | 0x100000;
  if ((uVar8 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar9 = -(uVar9 + bVar14);
  }
  if (uVar11 == uVar12) {
    uVar9 = uVar9 ^ 0x100000;
    if (uVar11 == 0) {
      uVar6 = uVar6 ^ 0x100000;
      uVar11 = 1;
    }
    else {
      uVar12 = uVar12 - 1;
    }
  }
  uVar8 = -uVar12 + 0x20;
  if ((int)uVar12 < 0x21) {
    uVar13 = param_3 << (uVar8 & 0xff);
    param_3 = param_3 >> (uVar12 & 0xff);
    uVar5 = uVar7 + param_3;
    uVar2 = uVar9 << (uVar8 & 0xff);
    uVar8 = uVar5 + uVar2;
    uVar12 = uVar6 + CARRY4(uVar7,param_3) + ((int)uVar9 >> (uVar12 & 0xff)) +
             (uint)CARRY4(uVar5,uVar2);
  }
  else {
    uVar13 = uVar9 << (-uVar12 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar13 = uVar13 | 2;
    }
    uVar12 = (int)uVar9 >> (uVar12 - 0x20 & 0xff);
    uVar8 = uVar7 + uVar12;
    uVar12 = uVar6 + ((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar7,uVar12);
  }
  param_2 = uVar12 & 0x80000000;
  uVar7 = uVar12;
  if ((int)uVar12 < 0) {
    bVar14 = uVar13 == 0;
    uVar13 = -uVar13;
    uVar7 = -uVar8;
    uVar8 = -(uVar8 + !bVar14);
    uVar7 = -(uVar12 + (bVar14 <= uVar7));
  }
  if (0xfffff < uVar7) {
    uVar9 = uVar11 - 1;
    if (0x1fffff < uVar7) {
      bVar3 = (byte)uVar7;
      uVar7 = uVar7 >> 1;
      bVar4 = (byte)uVar8;
      uVar8 = (uint)(bVar3 & 1) << 0x1f | uVar8 >> 1;
      uVar13 = (uint)(bVar4 & 1) << 0x1f | uVar13 >> 1;
      uVar9 = uVar11;
      if (0xffbfffff < uVar11 * 0x200000) goto LAB_000977f0;
    }
LAB_00097698:
    bVar14 = 0x7fffffff < uVar13;
    if (uVar13 == 0x80000000) {
      bVar14 = (bool)((byte)uVar8 & 1);
    }
    return CONCAT44(uVar7 + uVar9 * 0x100000 + (uint)CARRY4(uVar8,(uint)bVar14) | param_2,
                    uVar8 + bVar14);
  }
  bVar3 = (byte)(uVar13 >> 0x1f);
  uVar13 = uVar13 << 1;
  uVar9 = uVar8 * 2;
  bVar14 = CARRY4(uVar8,uVar8);
  uVar8 = uVar8 * 2 + (uint)bVar3;
  uVar7 = uVar7 * 2 + (uint)(bVar14 || CARRY4(uVar9,(uint)bVar3));
  uVar9 = uVar11 - 2;
  if ((uVar7 & 0x100000) != 0) goto LAB_00097698;
  uVar11 = uVar8;
  uVar6 = uVar7;
  if (uVar7 == 0) {
    uVar11 = 0;
    uVar6 = uVar8;
  }
  iVar10 = LZCOUNT(uVar6);
  if (uVar7 == 0) {
    iVar10 = iVar10 + 0x20;
  }
  uVar7 = iVar10 - 0xb;
  bVar16 = SBORROW4(uVar7,0x20);
  uVar8 = iVar10 - 0x2b;
  bVar14 = (int)uVar8 < 0;
  bVar15 = uVar8 == 0;
  if ((int)uVar7 < 0x20) {
    bVar16 = SCARRY4(uVar8,0xc);
    iVar10 = iVar10 + -0x1f;
    bVar14 = iVar10 < 0;
    bVar15 = iVar10 == 0;
    uVar8 = uVar7;
    if (!bVar15 && bVar14 == bVar16) {
      uVar11 = uVar6 << (uVar7 & 0xff);
      uVar6 = uVar6 >> (0xcU - iVar10 & 0xff);
      goto LAB_00097718;
    }
  }
  if (bVar15 || bVar14 != bVar16) {
    uVar13 = 0x20 - uVar8;
  }
  uVar6 = uVar6 << (uVar8 & 0xff);
  if (bVar15 || bVar14 != bVar16) {
    uVar6 = uVar6 | uVar11 >> (uVar13 & 0xff);
    uVar11 = uVar11 << (uVar8 & 0xff);
  }
LAB_00097718:
  if ((int)uVar7 <= (int)uVar9) {
    return CONCAT44(uVar6 + (uVar9 - uVar7) * 0x100000 | param_2,uVar11);
  }
  uVar8 = ~(uVar9 - uVar7);
  if ((int)uVar8 < 0x1f) {
    iVar10 = uVar8 - 0x13;
    if (iVar10 != 0 && iVar10 < 0 == SCARRY4(uVar8 - 0x1f,0xc)) {
      return CONCAT44(uVar12,uVar11 >> (0x20 - (0xcU - iVar10) & 0xff) |
                             uVar6 << (0xcU - iVar10 & 0xff)) & 0x80000000ffffffff;
    }
    uVar8 = uVar8 + 1;
    return CONCAT44(param_2 | uVar6 >> (uVar8 & 0xff),
                    uVar11 >> (uVar8 & 0xff) | uVar6 << (0x20 - uVar8 & 0xff));
  }
  return CONCAT44(uVar12,uVar6 >> (uVar8 - 0x1f & 0xff)) & 0x80000000ffffffff;
}

