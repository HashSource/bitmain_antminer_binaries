
UDItype __udivmoddi4(UDItype n,UDItype d,UDItype *rp)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  uVar9 = (uint)(d >> 0x20);
  uVar10 = (uint)d;
  uVar3 = (uint)(n >> 0x20);
  uVar2 = (uint)n;
  bVar13 = uVar9 <= uVar3;
  if (uVar3 == uVar9) {
    bVar13 = uVar10 <= uVar2;
  }
  if (bVar13) {
    iVar7 = LZCOUNT(uVar9);
    if (uVar9 == 0) {
      iVar7 = LZCOUNT(uVar10) + 0x20;
    }
    iVar5 = LZCOUNT(uVar3);
    if (uVar3 == 0) {
      iVar5 = LZCOUNT(uVar2) + 0x20;
    }
    uVar4 = iVar7 - iVar5;
    uVar8 = uVar10 << (uVar4 & 0xff);
    uVar10 = uVar9 << (uVar4 & 0xff) | uVar10 << (uVar4 - 0x20 & 0xff) |
             uVar10 >> (0x20 - uVar4 & 0xff);
    bVar13 = uVar10 <= uVar3;
    if (uVar3 == uVar10) {
      bVar13 = uVar8 <= uVar2;
    }
    if (bVar13) {
      uVar2 = 1 << (uVar4 & 0xff);
      uVar3 = 1 << (uVar4 - 0x20 & 0xff) | 1U >> (0x20 - uVar4 & 0xff);
      n = n - CONCAT44(uVar10,uVar8);
    }
    else {
      uVar2 = 0;
      uVar3 = 0;
    }
    if (uVar4 != 0) {
      uVar11 = uVar10 >> 1;
      uVar9 = (uint)((uVar10 & 1) != 0) << 0x1f | uVar8 >> 1;
      uVar10 = uVar4;
      do {
        while( true ) {
          uVar12 = (uint)(n >> 0x20);
          uVar8 = (uint)n;
          bVar13 = uVar11 <= uVar12;
          if (uVar12 == uVar11) {
            bVar13 = uVar9 <= uVar8;
          }
          if (bVar13) break;
          uVar6 = uVar8 * 2;
          uVar8 = uVar12 * 2 + (uint)CARRY4(uVar8,uVar8);
          n = CONCAT44(uVar8,uVar6);
          uVar10 = uVar10 - 1;
          if (uVar10 == 0) goto LAB_001eb476;
        }
        lVar1 = n - CONCAT44(uVar11,uVar9);
        uVar8 = (uint)lVar1;
        uVar6 = uVar8 * 2 + 1;
        uVar8 = (int)((ulonglong)lVar1 >> 0x20) * 2 + (uint)CARRY4(uVar8,uVar8) +
                (uint)(0xfffffffe < uVar8 * 2);
        n = CONCAT44(uVar8,uVar6);
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
LAB_001eb476:
      uVar12 = uVar8 >> (uVar4 & 0xff);
      bVar13 = CARRY4(uVar2,uVar6);
      uVar10 = uVar2 + uVar6;
      uVar9 = uVar6 >> (uVar4 & 0xff) | uVar8 << (0x20 - uVar4 & 0xff) |
              uVar8 >> (uVar4 - 0x20 & 0xff);
      n = CONCAT44(uVar12,uVar9);
      uVar11 = uVar9 << (uVar4 & 0xff);
      uVar2 = uVar10 - uVar11;
      uVar3 = ((uVar3 + uVar8 + (uint)bVar13) -
              (uVar12 << (uVar4 & 0xff) | uVar9 << (uVar4 - 0x20 & 0xff) |
              uVar9 >> (0x20 - uVar4 & 0xff))) - (uint)(uVar10 < uVar11);
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

