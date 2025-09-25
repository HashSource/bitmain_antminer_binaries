
ulong bn_mul_add_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulong *puVar1;
  ulong *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  if (num < 1) {
    return 0;
  }
  uVar4 = num & 0xfffffffc;
  if (uVar4 != 0) {
    uVar4 = 0;
    puVar1 = rp + 4;
    puVar2 = ap + 4;
    do {
      ap = puVar2;
      rp = puVar1;
      num = num - 4;
      uVar6 = rp[-4];
      uVar3 = rp[-3];
      uVar7 = ap[-4] * w + uVar4;
      rp[-4] = uVar7 + uVar6;
      uVar5 = (uint)(uVar7 < uVar4);
      if (CARRY4(uVar7,uVar6)) {
        uVar5 = (uVar7 < uVar4) + 1;
      }
      uVar6 = ap[-3] * w + uVar5;
      rp[-3] = uVar6 + uVar3;
      uVar4 = (uVar6 < uVar5) + 1;
      if (!CARRY4(uVar6,uVar3)) {
        uVar4 = (uint)(uVar6 < uVar5);
      }
      uVar6 = rp[-2];
      uVar3 = ap[-2] * w + uVar4;
      rp[-2] = uVar3 + uVar6;
      uVar5 = (uint)(uVar3 < uVar4);
      if (CARRY4(uVar3,uVar6)) {
        uVar5 = (uVar3 < uVar4) + 1;
      }
      uVar6 = rp[-1];
      uVar3 = ap[-1] * w + uVar5;
      rp[-1] = uVar3 + uVar6;
      uVar4 = (uint)(uVar3 < uVar5);
      if (CARRY4(uVar3,uVar6)) {
        uVar4 = (uVar3 < uVar5) + 1;
      }
      puVar1 = rp + 4;
      puVar2 = ap + 4;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return uVar4;
    }
  }
  uVar3 = *ap * w + uVar4;
  uVar5 = (uVar3 < uVar4) + 1;
  if (!CARRY4(*rp,uVar3)) {
    uVar5 = (uint)(uVar3 < uVar4);
  }
  *rp = *rp + uVar3;
  if (num != 1) {
    uVar4 = ap[1] * w + uVar5;
    bVar8 = uVar4 < uVar5;
    uVar5 = (uint)bVar8;
    if (CARRY4(uVar4,rp[1])) {
      uVar5 = bVar8 + 1;
    }
    rp[1] = uVar4 + rp[1];
    if (num != 2) {
      uVar4 = ap[2] * w + uVar5;
      bVar8 = uVar4 < uVar5;
      uVar5 = (uint)bVar8;
      if (CARRY4(uVar4,rp[2])) {
        uVar5 = bVar8 + 1;
      }
      rp[2] = uVar4 + rp[2];
    }
  }
  return uVar5;
}

