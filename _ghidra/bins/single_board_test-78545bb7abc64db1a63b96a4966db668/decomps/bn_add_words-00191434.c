
ulong bn_add_words(ulong *rp,ulong *ap,ulong *bp,int num)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  uint in_r12;
  uint uVar9;
  
  if (num < 1) {
    return 0;
  }
  if ((num & 0xfffffffcU) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = 0;
    puVar1 = rp + 4;
    puVar2 = bp + 4;
    puVar3 = ap + 4;
    do {
      ap = puVar3;
      bp = puVar2;
      rp = puVar1;
      uVar5 = ap[-4];
      num = num - 4;
      uVar4 = bp[-4];
      uVar6 = uVar5 + uVar9;
      rp[-4] = uVar6 + uVar4;
      if (CARRY4(uVar6,uVar4)) {
        in_r12 = 1;
      }
      uVar7 = ap[-3];
      if (!CARRY4(uVar6,uVar4)) {
        in_r12 = 0;
      }
      uVar4 = bp[-3];
      uVar5 = CARRY4(uVar5,uVar9) + in_r12;
      uVar9 = uVar5 + uVar7;
      rp[-3] = uVar9 + uVar4;
      if (CARRY4(uVar9,uVar4)) {
        in_r12 = 1;
      }
      uVar6 = ap[-2];
      if (!CARRY4(uVar9,uVar4)) {
        in_r12 = 0;
      }
      uVar9 = bp[-2];
      uVar4 = CARRY4(uVar5,uVar7) + in_r12;
      uVar5 = uVar4 + uVar6;
      rp[-2] = uVar5 + uVar9;
      if (CARRY4(uVar5,uVar9)) {
        in_r12 = 1;
      }
      uVar7 = ap[-1];
      if (!CARRY4(uVar5,uVar9)) {
        in_r12 = 0;
      }
      uVar9 = CARRY4(uVar4,uVar6) + in_r12;
      uVar4 = uVar9 + uVar7;
      in_r12 = (uint)CARRY4(uVar4,bp[-1]);
      rp[-1] = uVar4 + bp[-1];
      uVar9 = CARRY4(uVar9,uVar7) + in_r12;
      puVar1 = rp + 4;
      puVar2 = bp + 4;
      puVar3 = ap + 4;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return uVar9;
    }
  }
  uVar4 = *ap;
  uVar6 = *bp;
  uVar5 = uVar9 + uVar4;
  *rp = uVar5 + uVar6;
  uVar8 = (uint)CARRY4(uVar5,uVar6) + (uint)CARRY4(uVar9,uVar4);
  if (num != 1) {
    uVar9 = ap[1];
    uVar5 = bp[1];
    uVar4 = uVar9 + uVar8;
    rp[1] = uVar4 + uVar5;
    uVar8 = (uint)CARRY4(uVar9,uVar8) + (uint)CARRY4(uVar4,uVar5);
    if (num != 2) {
      uVar9 = ap[2] + uVar8;
      uVar8 = (uint)CARRY4(ap[2],uVar8) + (uint)CARRY4(uVar9,bp[2]);
      rp[2] = uVar9 + bp[2];
    }
  }
  return uVar8;
}

