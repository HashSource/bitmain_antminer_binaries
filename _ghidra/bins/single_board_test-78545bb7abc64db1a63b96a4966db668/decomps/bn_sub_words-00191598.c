
ulong bn_sub_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  ulong *puVar1;
  uint *puVar2;
  ulong *puVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  if (num < 1) {
    return 0;
  }
  if ((num & 0xfffffffcU) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = 0;
    puVar1 = rp + 4;
    puVar2 = ap + 4;
    puVar3 = bp + 4;
    do {
      bp = puVar3;
      ap = puVar2;
      rp = puVar1;
      uVar5 = bp[-4];
      uVar6 = ap[-4];
      num = num - 4;
      bVar12 = uVar6 < uVar5;
      bVar11 = uVar6 != uVar5;
      uVar4 = (uVar6 - uVar5) - uVar9;
      if (bVar12) {
        uVar5 = 1;
      }
      rp[-4] = uVar4;
      if (!bVar12) {
        uVar5 = 0;
      }
      uVar8 = ap[-3];
      if (bVar11) {
        uVar4 = uVar5;
      }
      uVar6 = bp[-3];
      if (!bVar11) {
        uVar5 = uVar9;
        uVar4 = uVar9;
      }
      bVar12 = uVar8 < uVar6;
      bVar11 = uVar8 == uVar6;
      uVar9 = uVar6;
      if (bVar11) {
        uVar9 = uVar4;
      }
      rp[-3] = (uVar8 - uVar6) - uVar4;
      if (bVar12) {
        uVar8 = 1;
      }
      uVar4 = bp[-2];
      if (!bVar12) {
        uVar8 = 0;
      }
      uVar6 = ap[-2];
      if (!bVar11) {
        uVar5 = uVar8;
        uVar9 = uVar8;
      }
      iVar7 = uVar6 - uVar4;
      bVar12 = uVar6 < uVar4;
      bVar11 = uVar6 != uVar4;
      if (bVar12) {
        uVar4 = 1;
      }
      rp[-2] = iVar7 - uVar9;
      if (!bVar12) {
        uVar4 = 0;
      }
      uVar6 = bp[-1];
      if (bVar11) {
        uVar5 = uVar4;
      }
      uVar10 = ap[-1];
      if (!bVar11) {
        uVar4 = uVar9;
      }
      uVar9 = (ulong)(uVar10 < uVar6);
      uVar8 = uVar9;
      if (uVar10 == uVar6) {
        uVar9 = uVar5;
        uVar8 = uVar4;
      }
      rp[-1] = (uVar10 - uVar6) - uVar4;
      puVar1 = rp + 4;
      puVar2 = ap + 4;
      puVar3 = bp + 4;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return uVar8;
    }
  }
  uVar10 = *bp;
  uVar6 = *ap;
  uVar4 = (uVar6 - uVar10) - uVar9;
  if (uVar10 != uVar6) {
    uVar9 = (uint)(uVar6 < uVar10);
  }
  *rp = uVar4;
  uVar4 = uVar9;
  if (num != 1) {
    uVar10 = bp[1];
    uVar6 = ap[1];
    uVar4 = (uint)(uVar6 < uVar10);
    if (uVar6 == uVar10) {
      uVar4 = uVar9;
    }
    rp[1] = (uVar6 - uVar10) - uVar9;
    if (num != 2) {
      uVar6 = bp[2];
      uVar10 = ap[2];
      rp[2] = (uVar10 - uVar6) - uVar4;
      if (uVar10 != uVar6) {
        uVar4 = (uint)(uVar10 < uVar6);
      }
      return uVar4;
    }
  }
  return uVar4;
}

