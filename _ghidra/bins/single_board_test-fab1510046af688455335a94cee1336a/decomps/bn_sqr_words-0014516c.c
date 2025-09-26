
void bn_sqr_words(ulong *rp,ulong *ap,int num)

{
  longlong lVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong *puVar4;
  int iVar5;
  
  if (0 < num) {
    if ((num & 0xfffffffcU) != 0) {
      do {
        num = num - 4;
        *(ulonglong *)rp = (ulonglong)*ap * (ulonglong)*ap;
        *(ulonglong *)(rp + 2) = (ulonglong)ap[1] * (ulonglong)ap[1];
        *(ulonglong *)(rp + 4) = (ulonglong)ap[2] * (ulonglong)ap[2];
        puVar3 = ap + 3;
        ap = ap + 4;
        *(ulonglong *)(rp + 6) = (ulonglong)*puVar3 * (ulonglong)*puVar3;
        rp = rp + 8;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return;
      }
    }
    if (8 < num) {
      iVar5 = num - (num - 9U & 0xfffffff8);
      puVar4 = rp + 1;
      puVar3 = rp;
      puVar2 = ap;
      do {
        ap = puVar2 + 8;
        rp = puVar3 + 0x10;
        num = num - 8;
        HintPreloadData(puVar3 + 0x28);
        HintPreloadData(puVar3 + 0x30);
        lVar1 = (ulonglong)*puVar2 * (ulonglong)*puVar2;
        *puVar3 = (ulong)lVar1;
        *puVar4 = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar2[1] * (ulonglong)puVar2[1];
        puVar3[2] = (ulong)lVar1;
        puVar4[2] = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar2[2] * (ulonglong)puVar2[2];
        puVar3[4] = (ulong)lVar1;
        puVar4[4] = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar2[3] * (ulonglong)puVar2[3];
        puVar3[6] = (ulong)lVar1;
        puVar4[6] = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar2[4] * (ulonglong)puVar2[4];
        puVar3[8] = (ulong)lVar1;
        puVar4[8] = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar2[5] * (ulonglong)puVar2[5];
        puVar3[10] = (ulong)lVar1;
        puVar4[10] = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar2[6] * (ulonglong)puVar2[6];
        puVar3[0xc] = (ulong)lVar1;
        puVar4[0xc] = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar2[7] * (ulonglong)puVar2[7];
        puVar3[0xe] = (ulong)lVar1;
        puVar4[0xe] = (ulong)((ulonglong)lVar1 >> 0x20);
        puVar4 = puVar4 + 0x10;
        puVar3 = rp;
        puVar2 = ap;
      } while (num != iVar5 - 8U);
    }
    puVar3 = ap + -1;
    do {
      puVar3 = puVar3 + 1;
      num = num - 1;
      *(ulonglong *)rp = (ulonglong)*puVar3 * (ulonglong)*puVar3;
      rp = rp + 2;
    } while (num != 0);
  }
  return;
}

