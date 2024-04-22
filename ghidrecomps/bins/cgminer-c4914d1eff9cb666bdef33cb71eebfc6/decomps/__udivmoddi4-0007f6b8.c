
UDItype __udivmoddi4(UDItype n,UDItype d,UDItype *rp)

{
  uint uVar1;
  UDItype *in_r1;
  USItype lz2;
  uint uVar2;
  UDItype *in_r2;
  uint uVar3;
  UDItype *in_r3;
  uint uVar4;
  UDItype *pUVar5;
  UDItype *pUVar6;
  UDItype *pUVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  USItype k;
  USItype i;
  USItype lz1;
  bool bVar12;
  
  bVar12 = in_r3 <= in_r1;
  if (in_r1 == in_r3) {
    bVar12 = in_r2 <= rp;
  }
  if (bVar12) {
    iVar10 = LZCOUNT(in_r3);
    if (in_r3 == (UDItype *)0x0) {
      iVar10 = LZCOUNT(in_r2) + 0x20;
    }
    lz2 = LZCOUNT(in_r1);
    if (in_r1 == (UDItype *)0x0) {
      lz2 = LZCOUNT(rp) + 0x20;
    }
    uVar11 = iVar10 - lz2;
    uVar8 = uVar11 - 0x20;
    uVar9 = 0x20 - uVar11;
    pUVar5 = (UDItype *)((int)in_r2 << (uVar11 & 0xff));
    pUVar6 = (UDItype *)
             ((int)in_r3 << (uVar11 & 0xff) | (int)in_r2 << (uVar8 & 0xff) |
             (uint)in_r2 >> (uVar9 & 0xff));
    bVar12 = pUVar6 <= in_r1;
    if (in_r1 == pUVar6) {
      bVar12 = pUVar5 <= rp;
    }
    if (bVar12) {
      bVar12 = rp < pUVar5;
      rp = (UDItype *)((int)rp - (int)pUVar5);
      uVar1 = 1 << (uVar11 & 0xff);
      in_r1 = (UDItype *)((int)in_r1 + (-(uint)bVar12 - (int)pUVar6));
      uVar2 = 1 << (uVar8 & 0xff) | 1U >> (uVar9 & 0xff);
    }
    else {
      uVar1 = 0;
      uVar2 = uVar1;
    }
    if (uVar11 != 0) {
      pUVar7 = (UDItype *)((uint)pUVar6 >> 1);
      pUVar5 = (UDItype *)((uint)(((uint)pUVar6 & 1) != 0) << 0x1f | (uint)pUVar5 >> 1);
      uVar3 = uVar11;
      do {
        while( true ) {
          bVar12 = pUVar7 <= in_r1;
          if (in_r1 == pUVar7) {
            bVar12 = pUVar5 <= rp;
          }
          if (bVar12) break;
          bVar12 = CARRY4((uint)rp,(uint)rp);
          rp = (UDItype *)((int)rp * 2);
          in_r1 = (UDItype *)((int)in_r1 * 2 + (uint)bVar12);
          uVar3 = uVar3 - 1;
          pUVar6 = in_r1;
          if (uVar3 == 0) goto LAB_0007f762;
        }
        bVar12 = rp < pUVar5;
        uVar4 = (int)rp - (int)pUVar5;
        rp = (UDItype *)(uVar4 * 2 + 1);
        in_r1 = (UDItype *)
                (((int)in_r1 + (-(uint)bVar12 - (int)pUVar7)) * 2 + (uint)CARRY4(uVar4,uVar4) +
                (uint)(0xfffffffe < uVar4 * 2));
        uVar3 = uVar3 - 1;
        pUVar6 = in_r1;
      } while (uVar3 != 0);
LAB_0007f762:
      in_r1 = (UDItype *)((uint)pUVar6 >> (uVar11 & 0xff));
      bVar12 = CARRY4(uVar1,(uint)rp);
      uVar3 = uVar1 + (int)rp;
      rp = (UDItype *)
           ((uint)rp >> (uVar11 & 0xff) | (int)pUVar6 << (uVar9 & 0xff) |
           (uint)pUVar6 >> (uVar8 & 0xff));
      uVar8 = (int)rp << (uVar11 & 0xff);
      uVar1 = uVar3 - uVar8;
      uVar2 = (int)pUVar6 +
              (((uVar2 + bVar12) -
               ((int)in_r1 << (uVar11 & 0xff) | (int)rp << (uVar11 - 0x20 & 0xff) |
               (uint)rp >> (0x20 - uVar11 & 0xff))) - (uint)(uVar3 < uVar8));
    }
  }
  else {
    uVar1 = 0;
    uVar2 = uVar1;
  }
  if ((UDItype **)n != (UDItype **)0x0) {
    *(UDItype **)n = rp;
    ((UDItype **)n)[1] = in_r1;
  }
  return CONCAT44(uVar2,uVar1);
}

