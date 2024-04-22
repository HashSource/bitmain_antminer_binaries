
uint __udivsi3(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  bool bVar28;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  bool bVar32;
  bool bVar33;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    if (param_1 != 0) {
      param_1 = 0xffffffff;
    }
    uVar1 = __aeabi_idiv0(param_1);
    return uVar1;
  }
  if (param_1 <= param_2) {
    return (uint)(param_1 == param_2);
  }
  if ((param_2 & param_2 - 1) == 0) {
    return param_1 >> (0x1fU - LZCOUNT(param_2) & 0xff);
  }
  iVar2 = 0x1f - (LZCOUNT(param_2) - LZCOUNT(param_1));
  if (iVar2 == 0) {
    bVar3 = param_2 << 0x1f <= param_1;
    if (bVar3) {
      param_1 = param_1 + param_2 * -0x80000000;
    }
    bVar4 = param_2 << 0x1e <= param_1;
    if (bVar4) {
      param_1 = param_1 + param_2 * -0x40000000;
    }
    bVar5 = param_2 << 0x1d <= param_1;
    if (bVar5) {
      param_1 = param_1 + param_2 * -0x20000000;
    }
    bVar6 = param_2 << 0x1c <= param_1;
    if (bVar6) {
      param_1 = param_1 + param_2 * -0x10000000;
    }
    bVar7 = param_2 << 0x1b <= param_1;
    if (bVar7) {
      param_1 = param_1 + param_2 * -0x8000000;
    }
    bVar8 = param_2 << 0x1a <= param_1;
    if (bVar8) {
      param_1 = param_1 + param_2 * -0x4000000;
    }
    bVar9 = param_2 << 0x19 <= param_1;
    if (bVar9) {
      param_1 = param_1 + param_2 * -0x2000000;
    }
    bVar10 = param_2 << 0x18 <= param_1;
    if (bVar10) {
      param_1 = param_1 + param_2 * -0x1000000;
    }
    bVar11 = param_2 << 0x17 <= param_1;
    if (bVar11) {
      param_1 = param_1 + param_2 * -0x800000;
    }
    bVar12 = param_2 << 0x16 <= param_1;
    if (bVar12) {
      param_1 = param_1 + param_2 * -0x400000;
    }
    bVar13 = param_2 << 0x15 <= param_1;
    if (bVar13) {
      param_1 = param_1 + param_2 * -0x200000;
    }
    bVar14 = param_2 << 0x14 <= param_1;
    if (bVar14) {
      param_1 = param_1 + param_2 * -0x100000;
    }
    bVar15 = param_2 << 0x13 <= param_1;
    if (bVar15) {
      param_1 = param_1 + param_2 * -0x80000;
    }
    bVar16 = param_2 << 0x12 <= param_1;
    if (bVar16) {
      param_1 = param_1 + param_2 * -0x40000;
    }
    bVar17 = param_2 << 0x11 <= param_1;
    if (bVar17) {
      param_1 = param_1 + param_2 * -0x20000;
    }
    bVar18 = param_2 << 0x10 <= param_1;
    if (bVar18) {
      param_1 = param_1 + param_2 * -0x10000;
    }
    bVar19 = param_2 << 0xf <= param_1;
    if (bVar19) {
      param_1 = param_1 + param_2 * -0x8000;
    }
    bVar20 = param_2 << 0xe <= param_1;
    if (bVar20) {
      param_1 = param_1 + param_2 * -0x4000;
    }
    bVar21 = param_2 << 0xd <= param_1;
    if (bVar21) {
      param_1 = param_1 + param_2 * -0x2000;
    }
    bVar22 = param_2 << 0xc <= param_1;
    if (bVar22) {
      param_1 = param_1 + param_2 * -0x1000;
    }
    bVar23 = param_2 << 0xb <= param_1;
    if (bVar23) {
      param_1 = param_1 + param_2 * -0x800;
    }
    bVar24 = param_2 << 10 <= param_1;
    if (bVar24) {
      param_1 = param_1 + param_2 * -0x400;
    }
    bVar25 = param_2 << 9 <= param_1;
    if (bVar25) {
      param_1 = param_1 + param_2 * -0x200;
    }
    bVar26 = param_2 << 8 <= param_1;
    if (bVar26) {
      param_1 = param_1 + param_2 * -0x100;
    }
    bVar27 = param_2 << 7 <= param_1;
    if (bVar27) {
      param_1 = param_1 + param_2 * -0x80;
    }
    bVar28 = param_2 << 6 <= param_1;
    if (bVar28) {
      param_1 = param_1 + param_2 * -0x40;
    }
    bVar29 = param_2 << 5 <= param_1;
    if (bVar29) {
      param_1 = param_1 + param_2 * -0x20;
    }
    bVar30 = param_2 << 4 <= param_1;
    if (bVar30) {
      param_1 = param_1 + param_2 * -0x10;
    }
    bVar31 = param_2 << 3 <= param_1;
    if (bVar31) {
      param_1 = param_1 + param_2 * -8;
    }
    bVar32 = param_2 << 2 <= param_1;
    if (bVar32) {
      param_1 = param_1 + param_2 * -4;
    }
    bVar33 = param_2 << 1 <= param_1;
    if (bVar33) {
      param_1 = param_1 + param_2 * -2;
    }
    return (((((((((((((((((((((((((((((((uint)bVar3 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 +
                                      (uint)bVar6) * 2 + (uint)bVar7) * 2 + (uint)bVar8) * 2 +
                                   (uint)bVar9) * 2 + (uint)bVar10) * 2 + (uint)bVar11) * 2 +
                                (uint)bVar12) * 2 + (uint)bVar13) * 2 + (uint)bVar14) * 2 +
                             (uint)bVar15) * 2 + (uint)bVar16) * 2 + (uint)bVar17) * 2 +
                          (uint)bVar18) * 2 + (uint)bVar19) * 2 + (uint)bVar20) * 2 + (uint)bVar21)
                       * 2 + (uint)bVar22) * 2 + (uint)bVar23) * 2 + (uint)bVar24) * 2 +
                   (uint)bVar25) * 2 + (uint)bVar26) * 2 + (uint)bVar27) * 2 + (uint)bVar28) * 2 +
               (uint)bVar29) * 2 + (uint)bVar30) * 2 + (uint)bVar31) * 2 + (uint)bVar32) * 2 +
           (uint)bVar33) * 2 + (uint)(param_2 <= param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x0009715c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(iVar2 * 0xc + 0x97164))();
  return uVar1;
}

