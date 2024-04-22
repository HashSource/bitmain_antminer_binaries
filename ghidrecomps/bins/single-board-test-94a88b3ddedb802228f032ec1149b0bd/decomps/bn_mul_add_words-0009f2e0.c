
ulong bn_mul_add_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  ulong *puVar5;
  ulong *puVar6;
  ulong *puVar7;
  uint local_64;
  
  if (num < 1) {
    uVar3 = 0;
  }
  else {
    uVar3 = num & 0xfffffffc;
    local_64 = num;
    if (uVar3 != 0) {
      puVar6 = rp + 4;
      uVar3 = 0;
      puVar5 = puVar6;
      puVar7 = rp;
      do {
        rp = puVar5;
        num = num - 4;
        uVar1 = (ulonglong)w * (ulonglong)*ap + (ulonglong)puVar6[-4] + (ulonglong)uVar3;
        puVar6[-4] = (ulong)uVar1;
        puVar6 = puVar6 + 4;
        uVar1 = (ulonglong)w * (ulonglong)ap[1] + (ulonglong)puVar7[1] + (uVar1 >> 0x20);
        puVar7[1] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)ap[2] + (ulonglong)puVar7[2] + (uVar1 >> 0x20);
        puVar7[2] = (ulong)uVar1;
        puVar5 = ap + 3;
        ap = ap + 4;
        lVar2 = (ulonglong)w * (ulonglong)*puVar5 + (ulonglong)puVar7[3] + (uVar1 >> 0x20);
        uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
        puVar7[3] = (ulong)lVar2;
        puVar5 = rp + 4;
        puVar7 = rp;
      } while ((num & 0xfffffffcU) != 0);
      local_64 = num;
      if (num == 0) {
        return uVar3;
      }
    }
    if (8 < (int)local_64) {
      iVar4 = local_64 - (local_64 - 9 & 0xfffffff8);
      puVar5 = ap;
      puVar7 = rp;
      do {
        rp = puVar7 + 8;
        ap = puVar5 + 8;
        uVar1 = (ulonglong)w * (ulonglong)*puVar5 +
                (ulonglong)CONCAT14(CARRY4(uVar3,*puVar7),uVar3 + *puVar7);
        local_64 = local_64 - 8;
        *puVar7 = (ulong)uVar1;
        HintPreloadData(puVar5 + 0x11);
        HintPreloadData(puVar7 + 0x11);
        uVar1 = (ulonglong)w * (ulonglong)puVar5[1] + (ulonglong)puVar7[1] + (uVar1 >> 0x20);
        puVar7[1] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar5[2] + (ulonglong)puVar7[2] + (uVar1 >> 0x20);
        puVar7[2] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar5[3] + (ulonglong)puVar7[3] + (uVar1 >> 0x20);
        puVar7[3] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar5[4] + (ulonglong)puVar7[4] + (uVar1 >> 0x20);
        puVar7[4] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar5[5] + (ulonglong)puVar7[5] + (uVar1 >> 0x20);
        puVar7[5] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar5[6] + (ulonglong)puVar7[6] + (uVar1 >> 0x20);
        puVar7[6] = (ulong)uVar1;
        lVar2 = (ulonglong)w * (ulonglong)puVar5[7] + (ulonglong)puVar7[7] + (uVar1 >> 0x20);
        uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
        puVar7[7] = (ulong)lVar2;
        puVar5 = ap;
        puVar7 = rp;
      } while (local_64 != iVar4 - 8U);
    }
    puVar5 = ap + -1;
    do {
      puVar5 = puVar5 + 1;
      lVar2 = (ulonglong)*puVar5 * (ulonglong)w + (ulonglong)uVar3 + (ulonglong)*rp;
      uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
      local_64 = local_64 - 1;
      *rp = (ulong)lVar2;
      rp = rp + 1;
    } while (local_64 != 0);
  }
  return uVar3;
}

