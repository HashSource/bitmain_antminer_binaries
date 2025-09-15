
ulong bn_sub_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  if (num < 1) {
    uVar6 = 0;
  }
  else {
    uVar6 = num & 0xfffffffc;
    if (uVar6 != 0) {
      uVar6 = 0;
      do {
        uVar7 = *ap;
        num = num - 4;
        uVar5 = *bp;
        *rp = (uVar7 - uVar5) - uVar6;
        if (uVar7 != uVar5) {
          uVar6 = (uint)(uVar7 < uVar5);
        }
        uVar7 = ap[1];
        uVar5 = bp[1];
        rp[1] = (uVar7 - uVar5) - uVar6;
        if (uVar7 != uVar5) {
          uVar6 = (uint)(uVar7 < uVar5);
        }
        uVar7 = ap[2];
        uVar5 = bp[2];
        uVar4 = uVar6;
        if (uVar7 != uVar5) {
          uVar4 = (uint)(uVar7 < uVar5);
        }
        rp[2] = (uVar7 - uVar5) - uVar6;
        uVar7 = ap[3];
        ap = ap + 4;
        uVar5 = bp[3];
        bp = bp + 4;
        uVar6 = uVar4;
        if (uVar7 != uVar5) {
          uVar6 = (uint)(uVar7 < uVar5);
        }
        rp[3] = (uVar7 - uVar5) - uVar4;
        rp = rp + 4;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return uVar6;
      }
    }
    if (8 < num) {
      iVar9 = num - (num - 9U & 0xfffffff8);
      puVar1 = bp;
      puVar2 = ap;
      puVar3 = rp;
      do {
        rp = puVar3 + 8;
        ap = puVar2 + 8;
        bp = puVar1 + 8;
        uVar5 = *puVar2;
        num = num - 8;
        uVar7 = *puVar1;
        HintPreloadData(puVar2 + 0xd);
        HintPreloadData(puVar1 + 0xd);
        *puVar3 = (uVar5 - uVar7) - uVar6;
        if (uVar5 != uVar7) {
          uVar6 = (uint)(uVar5 < uVar7);
        }
        uVar5 = puVar2[1];
        uVar7 = puVar1[1];
        puVar3[1] = (uVar5 - uVar7) - uVar6;
        if (uVar5 != uVar7) {
          uVar6 = (uint)(uVar5 < uVar7);
        }
        uVar5 = puVar2[2];
        uVar7 = puVar1[2];
        puVar3[2] = (uVar5 - uVar7) - uVar6;
        if (uVar5 != uVar7) {
          uVar6 = (uint)(uVar5 < uVar7);
        }
        uVar5 = puVar2[3];
        uVar7 = puVar1[3];
        puVar3[3] = (uVar5 - uVar7) - uVar6;
        if (uVar5 != uVar7) {
          uVar6 = (uint)(uVar5 < uVar7);
        }
        uVar5 = puVar2[4];
        uVar7 = puVar1[4];
        puVar3[4] = (uVar5 - uVar7) - uVar6;
        if (uVar5 != uVar7) {
          uVar6 = (uint)(uVar5 < uVar7);
        }
        uVar5 = puVar2[5];
        uVar7 = puVar1[5];
        puVar3[5] = (uVar5 - uVar7) - uVar6;
        if (uVar5 != uVar7) {
          uVar6 = (uint)(uVar5 < uVar7);
        }
        uVar5 = puVar2[6];
        uVar7 = puVar1[6];
        uVar4 = uVar6;
        if (uVar5 != uVar7) {
          uVar4 = (uint)(uVar5 < uVar7);
        }
        puVar3[6] = (uVar5 - uVar7) - uVar6;
        uVar5 = puVar2[7];
        uVar7 = puVar1[7];
        uVar6 = uVar4;
        if (uVar5 != uVar7) {
          uVar6 = (uint)(uVar5 < uVar7);
        }
        puVar3[7] = (uVar5 - uVar7) - uVar4;
        puVar1 = bp;
        puVar2 = ap;
        puVar3 = rp;
      } while (num != iVar9 - 8U);
    }
    iVar9 = 0;
    do {
      uVar7 = *(uint *)((int)ap + iVar9);
      uVar5 = *(uint *)((int)bp + iVar9);
      iVar8 = (uVar7 - uVar5) - uVar6;
      if (uVar7 != uVar5) {
        uVar6 = (uint)(uVar7 < uVar5);
      }
      num = num - 1;
      *(int *)((int)rp + iVar9) = iVar8;
      iVar9 = iVar9 + 4;
    } while (num != 0);
  }
  return uVar6;
}

