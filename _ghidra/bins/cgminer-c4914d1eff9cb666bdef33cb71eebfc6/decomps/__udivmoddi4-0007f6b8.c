
UDItype __udivmoddi4(UDItype n,UDItype d,UDItype *rp)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  bool bVar15;
  
  uVar2 = (uint)(n >> 0x20);
  uVar3 = (uint)n;
  uVar8 = (uint)(d >> 0x20);
  uVar9 = (uint)d;
  bVar15 = uVar8 <= uVar2;
  if (uVar2 == uVar8) {
    bVar15 = uVar9 <= uVar3;
  }
  if (bVar15) {
    iVar13 = LZCOUNT(uVar8);
    if (uVar8 == 0) {
      iVar13 = LZCOUNT(uVar9) + 0x20;
    }
    iVar4 = LZCOUNT(uVar2);
    if (uVar2 == 0) {
      iVar4 = LZCOUNT(uVar3) + 0x20;
    }
    uVar14 = iVar13 - iVar4;
    uVar11 = uVar14 - 0x20;
    uVar12 = 0x20 - uVar14;
    uVar7 = uVar9 << (uVar14 & 0xff);
    uVar9 = uVar8 << (uVar14 & 0xff) | uVar9 << (uVar11 & 0xff) | uVar9 >> (uVar12 & 0xff);
    bVar15 = uVar9 <= uVar2;
    if (uVar2 == uVar9) {
      bVar15 = uVar7 <= uVar3;
    }
    if (bVar15) {
      uVar2 = 1 << (uVar14 & 0xff);
      n = n - CONCAT44(uVar9,uVar7);
      uVar3 = 1 << (uVar11 & 0xff) | 1U >> (uVar12 & 0xff);
    }
    else {
      uVar2 = 0;
      uVar3 = uVar2;
    }
    if (uVar14 != 0) {
      uVar10 = uVar9 >> 1;
      uVar8 = (uint)((uVar9 & 1) != 0) << 0x1f | uVar7 >> 1;
      uVar9 = uVar14;
      do {
        while( true ) {
          uVar6 = (uint)(n >> 0x20);
          uVar7 = (uint)n;
          bVar15 = uVar10 <= uVar6;
          if (uVar6 == uVar10) {
            bVar15 = uVar8 <= uVar7;
          }
          if (bVar15) break;
          uVar5 = uVar7 * 2;
          uVar7 = uVar6 * 2 + (uint)CARRY4(uVar7,uVar7);
          n = CONCAT44(uVar7,uVar5);
          uVar9 = uVar9 - 1;
          if (uVar9 == 0) goto LAB_0007f762;
        }
        lVar1 = n - CONCAT44(uVar10,uVar8);
        uVar7 = (uint)lVar1;
        uVar5 = uVar7 * 2 + 1;
        uVar7 = (int)((ulonglong)lVar1 >> 0x20) * 2 + (uint)CARRY4(uVar7,uVar7) +
                (uint)(0xfffffffe < uVar7 * 2);
        n = CONCAT44(uVar7,uVar5);
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
LAB_0007f762:
      uVar8 = uVar7 >> (uVar14 & 0xff);
      bVar15 = CARRY4(uVar2,uVar5);
      uVar9 = uVar2 + uVar5;
      uVar11 = uVar5 >> (uVar14 & 0xff) | uVar7 << (uVar12 & 0xff) | uVar7 >> (uVar11 & 0xff);
      n = CONCAT44(uVar8,uVar11);
      uVar12 = uVar11 << (uVar14 & 0xff);
      uVar2 = uVar9 - uVar12;
      uVar3 = ((uVar7 + uVar3 + bVar15) -
              (uVar8 << (uVar14 & 0xff) | uVar11 << (uVar14 - 0x20 & 0xff) |
              uVar11 >> (0x20 - uVar14 & 0xff))) - (uint)(uVar9 < uVar12);
    }
  }
  else {
    uVar2 = 0;
    uVar3 = uVar2;
  }
  if (rp != (UDItype *)0x0) {
    *rp = n;
  }
  return CONCAT44(uVar3,uVar2);
}

