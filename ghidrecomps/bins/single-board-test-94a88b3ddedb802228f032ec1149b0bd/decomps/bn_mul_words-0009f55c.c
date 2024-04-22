
ulong bn_mul_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulonglong uVar1;
  longlong lVar2;
  ulong *puVar3;
  uint *puVar4;
  int iVar5;
  ulong local_34;
  
  if (num < 1) {
    local_34 = 0;
  }
  else {
    local_34 = num & 0xfffffffc;
    if (local_34 != 0) {
      local_34 = 0;
      do {
        num = num - 4;
        uVar1 = (ulonglong)w * (ulonglong)*ap + (ulonglong)local_34;
        *rp = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)ap[1] + (uVar1 >> 0x20);
        rp[1] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)ap[2] + (uVar1 >> 0x20);
        rp[2] = (ulong)uVar1;
        puVar4 = ap + 3;
        ap = ap + 4;
        lVar2 = (ulonglong)w * (ulonglong)*puVar4 + (uVar1 >> 0x20);
        rp[3] = (ulong)lVar2;
        rp = rp + 4;
        local_34 = (ulong)((ulonglong)lVar2 >> 0x20);
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return local_34;
      }
    }
    if (8 < num) {
      iVar5 = num - (num - 9U & 0xfffffff8);
      puVar4 = ap;
      puVar3 = rp;
      do {
        rp = puVar3 + 8;
        ap = puVar4 + 8;
        num = num - 8;
        uVar1 = (ulonglong)w * (ulonglong)*puVar4 + (ulonglong)local_34;
        HintPreloadData(puVar4 + 0x14);
        *puVar3 = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar4[1] + (uVar1 >> 0x20);
        puVar3[1] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar4[2] + (uVar1 >> 0x20);
        puVar3[2] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar4[3] + (uVar1 >> 0x20);
        puVar3[3] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar4[4] + (uVar1 >> 0x20);
        puVar3[4] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar4[5] + (uVar1 >> 0x20);
        puVar3[5] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar4[6] + (uVar1 >> 0x20);
        puVar3[6] = (ulong)uVar1;
        lVar2 = (ulonglong)w * (ulonglong)puVar4[7] + (uVar1 >> 0x20);
        local_34 = (ulong)((ulonglong)lVar2 >> 0x20);
        puVar3[7] = (ulong)lVar2;
        puVar4 = ap;
        puVar3 = rp;
      } while (num != iVar5 - 8U);
    }
    puVar4 = ap + -1;
    do {
      puVar4 = puVar4 + 1;
      num = num - 1;
      lVar2 = (ulonglong)*puVar4 * (ulonglong)w + (ulonglong)local_34;
      local_34 = (ulong)((ulonglong)lVar2 >> 0x20);
      *rp = (ulong)lVar2;
      rp = rp + 1;
    } while (num != 0);
  }
  return local_34;
}

