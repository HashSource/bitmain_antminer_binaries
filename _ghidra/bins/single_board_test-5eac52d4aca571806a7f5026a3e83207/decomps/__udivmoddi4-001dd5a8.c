
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
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  
  uVar5 = (uint)(d >> 0x20);
  uVar13 = (uint)d;
  uVar3 = (uint)(n >> 0x20);
  uVar2 = (uint)n;
  bVar15 = uVar5 <= uVar3;
  if (uVar3 == uVar5) {
    bVar15 = uVar13 <= uVar2;
  }
  if (bVar15) {
    iVar9 = LZCOUNT(uVar5);
    if (uVar5 == 0) {
      iVar9 = LZCOUNT(uVar13) + 0x20;
    }
    iVar4 = LZCOUNT(uVar3);
    if (uVar3 == 0) {
      iVar4 = LZCOUNT(uVar2) + 0x20;
    }
    uVar10 = iVar9 - iVar4;
    uVar14 = uVar10 - 0x20;
    uVar11 = 0x20 - uVar10;
    uVar12 = uVar13 << (uVar10 & 0xff);
    uVar13 = uVar5 << (uVar10 & 0xff) | uVar13 << (uVar14 & 0xff) | uVar13 >> (uVar11 & 0xff);
    bVar15 = uVar13 <= uVar3;
    if (uVar3 == uVar13) {
      bVar15 = uVar12 <= uVar2;
    }
    if (bVar15) {
      uVar2 = 1 << (uVar10 & 0xff);
      uVar3 = 1 << (uVar14 & 0xff) | 1U >> (uVar11 & 0xff);
      n = n - CONCAT44(uVar13,uVar12);
    }
    else {
      uVar2 = 0;
      uVar3 = 0;
    }
    if (uVar10 != 0) {
      uVar6 = uVar13 >> 1;
      uVar5 = (uint)((uVar13 & 1) != 0) << 0x1f | uVar12 >> 1;
      uVar13 = uVar10;
      do {
        while( true ) {
          uVar8 = (uint)(n >> 0x20);
          uVar12 = (uint)n;
          bVar15 = uVar6 <= uVar8;
          if (uVar8 == uVar6) {
            bVar15 = uVar5 <= uVar12;
          }
          if (bVar15) break;
          uVar7 = uVar12 * 2;
          uVar12 = uVar8 * 2 + (uint)CARRY4(uVar12,uVar12);
          n = CONCAT44(uVar12,uVar7);
          uVar13 = uVar13 - 1;
          if (uVar13 == 0) goto LAB_001dd656;
        }
        lVar1 = n - CONCAT44(uVar6,uVar5);
        uVar12 = (uint)lVar1;
        uVar7 = uVar12 * 2 + 1;
        uVar12 = (int)((ulonglong)lVar1 >> 0x20) * 2 + (uint)CARRY4(uVar12,uVar12) +
                 (uint)(0xfffffffe < uVar12 * 2);
        n = CONCAT44(uVar12,uVar7);
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
LAB_001dd656:
      uVar6 = uVar12 >> (uVar10 & 0xff);
      bVar15 = CARRY4(uVar2,uVar7);
      uVar13 = uVar2 + uVar7;
      uVar11 = uVar7 >> (uVar10 & 0xff) | uVar12 << (uVar11 & 0xff) | uVar12 >> (uVar14 & 0xff);
      uVar5 = uVar11 << (uVar10 & 0xff);
      uVar2 = uVar13 - uVar5;
      n = CONCAT44(uVar6,uVar11);
      uVar3 = ((uVar3 + uVar12 + (uint)bVar15) -
              (uVar6 << (uVar10 & 0xff) | uVar11 << (uVar10 - 0x20 & 0xff) |
              uVar11 >> (0x20 - uVar10 & 0xff))) - (uint)(uVar13 < uVar5);
    }
  }
  else {
    uVar2 = 0;
    uVar3 = 0;
  }
  if (rp != (UDItype *)0x0) {
    *rp = n;
  }
  return CONCAT44(uVar3,uVar2);
}

