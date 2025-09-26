
ulong bn_add_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  uint *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  if (num < 1) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    if ((num & 0xfffffffcU) != 0) {
      uVar4 = 0;
      do {
        uVar8 = *bp;
        uVar5 = *ap;
        num = num - 4;
        uVar6 = uVar5 + uVar8;
        *rp = uVar6 + uVar4;
        uVar6 = (uint)CARRY4(uVar5,uVar8) + (uint)CARRY4(uVar6,uVar4);
        uVar5 = ap[1] + bp[1];
        uVar8 = (uint)CARRY4(ap[1],bp[1]) + (uint)CARRY4(uVar5,uVar6);
        rp[1] = uVar5 + uVar6;
        uVar9 = bp[2];
        uVar5 = ap[2];
        uVar6 = uVar5 + uVar9;
        rp[2] = uVar6 + uVar8;
        uVar6 = (uint)CARRY4(uVar5,uVar9) + (uint)CARRY4(uVar6,uVar8);
        puVar1 = bp + 3;
        puVar2 = ap + 3;
        bp = bp + 4;
        ap = ap + 4;
        uVar5 = *puVar2 + *puVar1;
        uVar4 = (uint)CARRY4(*puVar2,*puVar1) + (uint)CARRY4(uVar5,uVar6);
        rp[3] = uVar5 + uVar6;
        rp = rp + 4;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return uVar4;
      }
    }
    if (8 < num) {
      iVar10 = num - (num - 9U & 0xfffffff8);
      puVar1 = bp;
      puVar2 = ap;
      puVar3 = rp;
      do {
        rp = puVar3 + 8;
        ap = puVar2 + 8;
        bp = puVar1 + 8;
        num = num - 8;
        HintPreloadData(puVar2 + 0x11);
        HintPreloadData(puVar1 + 0x11);
        uVar5 = *puVar2 + *puVar1;
        uVar6 = (uint)CARRY4(*puVar2,*puVar1) + (uint)CARRY4(uVar5,uVar4);
        *puVar3 = uVar5 + uVar4;
        uVar8 = puVar2[1] + puVar1[1];
        uVar5 = (uint)CARRY4(puVar2[1],puVar1[1]) + (uint)CARRY4(uVar8,uVar6);
        puVar3[1] = uVar8 + uVar6;
        uVar8 = puVar2[2] + puVar1[2];
        uVar6 = (uint)CARRY4(puVar2[2],puVar1[2]) + (uint)CARRY4(uVar8,uVar5);
        puVar3[2] = uVar8 + uVar5;
        uVar8 = puVar2[3] + puVar1[3];
        uVar5 = (uint)CARRY4(puVar2[3],puVar1[3]) + (uint)CARRY4(uVar8,uVar6);
        puVar3[3] = uVar8 + uVar6;
        uVar8 = puVar2[4] + puVar1[4];
        uVar6 = (uint)CARRY4(puVar2[4],puVar1[4]) + (uint)CARRY4(uVar8,uVar5);
        puVar3[4] = uVar8 + uVar5;
        uVar8 = puVar2[5] + puVar1[5];
        uVar5 = (uint)CARRY4(puVar2[5],puVar1[5]) + (uint)CARRY4(uVar8,uVar6);
        puVar3[5] = uVar8 + uVar6;
        uVar8 = puVar2[6] + puVar1[6];
        uVar6 = (uint)CARRY4(puVar2[6],puVar1[6]) + (uint)CARRY4(uVar8,uVar5);
        puVar3[6] = uVar8 + uVar5;
        uVar8 = puVar2[7];
        uVar5 = puVar1[7];
        uVar9 = uVar8 + uVar5;
        puVar3[7] = uVar9 + uVar6;
        uVar4 = (uint)CARRY4(uVar8,uVar5) + (uint)CARRY4(uVar9,uVar6);
        puVar1 = bp;
        puVar2 = ap;
        puVar3 = rp;
      } while (num != iVar10 - 8U);
    }
    iVar10 = 0;
    do {
      uVar5 = *(uint *)((int)ap + iVar10) + *(uint *)((int)bp + iVar10);
      iVar7 = uVar5 + uVar4;
      uVar4 = (uint)CARRY4(*(uint *)((int)ap + iVar10),*(uint *)((int)bp + iVar10)) +
              (uint)CARRY4(uVar5,uVar4);
      num = num - 1;
      *(int *)((int)rp + iVar10) = iVar7;
      iVar10 = iVar10 + 4;
    } while (num != 0);
  }
  return uVar4;
}

