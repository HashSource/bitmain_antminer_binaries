
void bn_sqr_words(ulong *rp,ulong *ap,int num)

{
  longlong lVar1;
  longlong *plVar2;
  ulong *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (0 < num) {
    if ((num & 0xfffffffcU) != 0) {
      do {
        num = num - 4;
        *(ulonglong *)rp = (ulonglong)*ap * (ulonglong)*ap;
        *(ulonglong *)((int)rp + 8) = (ulonglong)ap[1] * (ulonglong)ap[1];
        *(ulonglong *)((int)rp + 0x10) = (ulonglong)ap[2] * (ulonglong)ap[2];
        puVar3 = ap + 3;
        ap = ap + 4;
        *(ulonglong *)((int)rp + 0x18) = (ulonglong)*puVar3 * (ulonglong)*puVar3;
        rp = (ulong *)((int)rp + 0x20);
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return;
      }
    }
    if (8 < num) {
      iVar5 = num - (num - 9U & 0xfffffff8);
      puVar4 = (undefined4 *)((int)rp + 4);
      plVar2 = (longlong *)rp;
      puVar3 = ap;
      do {
        ap = puVar3 + 8;
        rp = (ulong *)(plVar2 + 8);
        num = num - 8;
        HintPreloadData(plVar2 + 0x14);
        HintPreloadData(plVar2 + 0x18);
        lVar1 = (ulonglong)*puVar3 * (ulonglong)*puVar3;
        *(int *)plVar2 = (int)lVar1;
        *puVar4 = (int)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar3[1] * (ulonglong)puVar3[1];
        *(int *)(plVar2 + 1) = (int)lVar1;
        puVar4[2] = (int)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar3[2] * (ulonglong)puVar3[2];
        *(int *)(plVar2 + 2) = (int)lVar1;
        puVar4[4] = (int)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar3[3] * (ulonglong)puVar3[3];
        *(int *)(plVar2 + 3) = (int)lVar1;
        puVar4[6] = (int)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar3[4] * (ulonglong)puVar3[4];
        *(int *)(plVar2 + 4) = (int)lVar1;
        puVar4[8] = (int)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar3[5] * (ulonglong)puVar3[5];
        *(int *)(plVar2 + 5) = (int)lVar1;
        puVar4[10] = (int)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar3[6] * (ulonglong)puVar3[6];
        *(int *)(plVar2 + 6) = (int)lVar1;
        puVar4[0xc] = (int)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)puVar3[7] * (ulonglong)puVar3[7];
        *(int *)(plVar2 + 7) = (int)lVar1;
        puVar4[0xe] = (int)((ulonglong)lVar1 >> 0x20);
        puVar4 = puVar4 + 0x10;
        plVar2 = (longlong *)rp;
        puVar3 = ap;
      } while (num != iVar5 - 8U);
    }
    puVar3 = ap + -1;
    do {
      puVar3 = puVar3 + 1;
      num = num - 1;
      *(ulonglong *)rp = (ulonglong)*puVar3 * (ulonglong)*puVar3;
      rp = (ulong *)((int)rp + 8);
    } while (num != 0);
  }
  return;
}

