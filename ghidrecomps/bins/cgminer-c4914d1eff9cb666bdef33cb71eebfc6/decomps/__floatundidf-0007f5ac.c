
ulonglong __floatundidf(uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  
  if ((param_1 | param_2) == 0) {
    return CONCAT44(param_2,param_1);
  }
  iVar7 = 0x432;
  uVar8 = param_2 >> 0x16;
  if (uVar8 != 0) {
    iVar7 = 3;
    if (param_2 >> 0x19 != 0) {
      iVar7 = 6;
    }
    if (param_2 >> 0x1c != 0) {
      iVar7 = iVar7 + 3;
    }
    uVar4 = iVar7 - ((int)param_2 >> 0x1f);
    uVar8 = param_1 << (0x20 - uVar4 & 0xff);
    param_1 = param_1 >> (uVar4 & 0xff) | param_2 << (0x20 - uVar4 & 0xff);
    param_2 = param_2 >> (uVar4 & 0xff);
    iVar7 = uVar4 + 0x432;
  }
  if (0xfffff < param_2) {
    if (0x1fffff < param_2) {
      uVar4 = param_2 & 1;
      param_2 = param_2 >> 1;
      bVar1 = (byte)param_1;
      param_1 = (uint)(uVar4 != 0) << 0x1f | param_1 >> 1;
      uVar8 = (uint)(bVar1 & 1) << 0x1f | uVar8 >> 1;
      iVar7 = iVar7 + 1;
      if (0xffbfffff < (uint)(iVar7 * 0x200000)) {
        return 0x7ff0000000000000;
      }
    }
LAB_0007f3b8:
    bVar10 = 0x7fffffff < uVar8;
    if (uVar8 == 0x80000000) {
      bVar10 = (param_1 & 1) != 0;
    }
    return CONCAT44(param_2 + iVar7 * 0x100000 + (uint)CARRY4(param_1,(uint)bVar10),param_1 + bVar10
                   );
  }
  bVar9 = (uVar8 & 0x80000000) != 0;
  uVar8 = uVar8 << 1;
  uVar4 = param_1 * 2;
  bVar10 = CARRY4(param_1,param_1);
  param_1 = param_1 * 2 + (uint)bVar9;
  param_2 = param_2 * 2 + (uint)(bVar10 || CARRY4(uVar4,(uint)bVar9));
  iVar7 = iVar7 + -1;
  if ((param_2 & 0x100000) != 0) goto LAB_0007f3b8;
  uVar2 = param_1;
  uVar4 = param_2;
  if (param_2 == 0) {
    uVar2 = 0;
    uVar4 = param_1;
  }
  iVar5 = LZCOUNT(uVar4);
  if (param_2 == 0) {
    iVar5 = iVar5 + 0x20;
  }
  uVar6 = iVar5 - 0xb;
  bVar11 = SBORROW4(uVar6,0x20);
  uVar3 = iVar5 - 0x2b;
  bVar10 = (int)uVar3 < 0;
  bVar9 = uVar3 == 0;
  if ((int)uVar6 < 0x20) {
    bVar11 = SCARRY4(uVar3,0xc);
    iVar5 = iVar5 + -0x1f;
    bVar10 = iVar5 < 0;
    bVar9 = iVar5 == 0;
    uVar3 = uVar6;
    if (!bVar9 && bVar10 == bVar11) {
      uVar2 = uVar4 << (uVar6 & 0xff);
      uVar4 = uVar4 >> (0xcU - iVar5 & 0xff);
      goto LAB_0007f430;
    }
  }
  if (bVar9 || bVar10 != bVar11) {
    uVar8 = 0x20 - uVar3;
  }
  uVar4 = uVar4 << (uVar3 & 0xff);
  if (bVar9 || bVar10 != bVar11) {
    uVar4 = uVar4 | uVar2 >> (uVar8 & 0xff);
    uVar2 = uVar2 << (uVar3 & 0xff);
  }
LAB_0007f430:
  if ((int)uVar6 <= iVar7) {
    return CONCAT44(uVar4 + (iVar7 - uVar6) * 0x100000,uVar2);
  }
  uVar8 = ~(iVar7 - uVar6);
  if (0x1e < (int)uVar8) {
    return (ulonglong)(uVar4 >> (uVar8 - 0x1f & 0xff));
  }
  iVar7 = uVar8 - 0x13;
  if (iVar7 == 0 || iVar7 < 0 != SCARRY4(uVar8 - 0x1f,0xc)) {
    uVar8 = uVar8 + 1;
    return CONCAT44(uVar4 >> (uVar8 & 0xff),uVar2 >> (uVar8 & 0xff) | uVar4 << (0x20 - uVar8 & 0xff)
                   );
  }
  return (ulonglong)(uVar2 >> (0x20 - (0xcU - iVar7) & 0xff) | uVar4 << (0xcU - iVar7 & 0xff));
}

