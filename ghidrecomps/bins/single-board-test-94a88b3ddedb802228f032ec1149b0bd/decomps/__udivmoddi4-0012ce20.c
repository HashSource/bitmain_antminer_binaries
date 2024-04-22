
UDItype __udivmoddi4(UDItype n,UDItype d,UDItype *rp)

{
  uint uVar1;
  UDItype *in_r1;
  uint uVar2;
  USItype lz2;
  UDItype *in_r2;
  UDItype *in_r3;
  UDItype *pUVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  USItype k;
  USItype i;
  USItype lz1;
  uint uVar7;
  UDItype *pUVar8;
  UDItype *pUVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  bVar12 = in_r3 <= in_r1;
  if (in_r1 == in_r3) {
    bVar12 = in_r2 <= rp;
  }
  if (bVar12) {
    iVar5 = LZCOUNT(in_r3);
    if (in_r3 == (UDItype *)0x0) {
      iVar5 = LZCOUNT(in_r2) + 0x20;
    }
    lz2 = LZCOUNT(in_r1);
    if (in_r1 == (UDItype *)0x0) {
      lz2 = LZCOUNT(rp) + 0x20;
    }
    uVar6 = iVar5 - lz2;
    uVar11 = uVar6 - 0x20;
    uVar7 = 0x20 - uVar6;
    pUVar8 = (UDItype *)((int)in_r2 << (uVar6 & 0xff));
    pUVar9 = (UDItype *)
             ((int)in_r3 << (uVar6 & 0xff) | (int)in_r2 << (uVar11 & 0xff) |
             (uint)in_r2 >> (uVar7 & 0xff));
    bVar12 = pUVar9 <= in_r1;
    if (in_r1 == pUVar9) {
      bVar12 = pUVar8 <= rp;
    }
    if (bVar12) {
      bVar12 = rp < pUVar8;
      rp = (UDItype *)((int)rp - (int)pUVar8);
      uVar1 = 1 << (uVar6 & 0xff);
      uVar2 = 1 << (uVar11 & 0xff) | 1U >> (uVar7 & 0xff);
      in_r1 = (UDItype *)((int)in_r1 + (-(uint)bVar12 - (int)pUVar9));
    }
    else {
      uVar1 = 0;
      uVar2 = 0;
    }
    if (uVar6 != 0) {
      pUVar3 = (UDItype *)((uint)pUVar9 >> 1);
      pUVar8 = (UDItype *)((uint)(((uint)pUVar9 & 1) != 0) << 0x1f | (uint)pUVar8 >> 1);
      uVar10 = uVar6;
      do {
        while( true ) {
          bVar12 = pUVar3 <= in_r1;
          if (in_r1 == pUVar3) {
            bVar12 = pUVar8 <= rp;
          }
          if (bVar12) break;
          bVar12 = CARRY4((uint)rp,(uint)rp);
          rp = (UDItype *)((int)rp * 2);
          in_r1 = (UDItype *)((int)in_r1 * 2 + (uint)bVar12);
          uVar10 = uVar10 - 1;
          pUVar9 = in_r1;
          if (uVar10 == 0) goto LAB_0012cece;
        }
        bVar12 = rp < pUVar8;
        uVar4 = (int)rp - (int)pUVar8;
        rp = (UDItype *)(uVar4 * 2 + 1);
        in_r1 = (UDItype *)
                (((int)in_r1 + (-(uint)bVar12 - (int)pUVar3)) * 2 + (uint)CARRY4(uVar4,uVar4) +
                (uint)(0xfffffffe < uVar4 * 2));
        uVar10 = uVar10 - 1;
        pUVar9 = in_r1;
      } while (uVar10 != 0);
LAB_0012cece:
      in_r1 = (UDItype *)((uint)pUVar9 >> (uVar6 & 0xff));
      bVar12 = CARRY4(uVar1,(uint)rp);
      uVar10 = uVar1 + (int)rp;
      rp = (UDItype *)
           ((uint)rp >> (uVar6 & 0xff) | (int)pUVar9 << (uVar7 & 0xff) |
           (uint)pUVar9 >> (uVar11 & 0xff));
      uVar7 = (int)rp << (uVar6 & 0xff);
      uVar1 = uVar10 - uVar7;
      uVar2 = (int)pUVar9 +
              (((bVar12 + uVar2) -
               ((int)in_r1 << (uVar6 & 0xff) | (int)rp << (uVar6 - 0x20 & 0xff) |
               (uint)rp >> (0x20 - uVar6 & 0xff))) - (uint)(uVar10 < uVar7));
    }
  }
  else {
    uVar1 = 0;
    uVar2 = 0;
  }
  if ((UDItype **)n != (UDItype **)0x0) {
    *(UDItype **)n = rp;
    ((UDItype **)n)[1] = in_r1;
  }
  return CONCAT44(uVar2,uVar1);
}

