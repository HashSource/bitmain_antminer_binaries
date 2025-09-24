
uint ssl3_pending(int param_1)

{
  int *piVar1;
  pitem *ppVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  pitem *local_14;
  
  if (*(int *)(param_1 + 0x658) == 0xf1) {
    return 0;
  }
  uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) & 8;
  if (uVar5 != 0) {
    uVar5 = 0;
    local_14 = pqueue_iterator(*(pqueue *)(*(int *)(param_1 + 0xf38) + 0x30));
    while (ppVar2 = pqueue_next(&local_14), ppVar2 != (pitem *)0x0) {
      uVar5 = uVar5 + *(int *)((int)ppVar2->data + 0x24);
    }
  }
  if ((*(int *)(param_1 + 0x65c) != 0) && (*(int *)(param_1 + 0x8fc) == 0x17)) {
    iVar3 = 0;
    iVar4 = param_1;
    do {
      iVar3 = iVar3 + 1;
      uVar5 = uVar5 + *(int *)(iVar4 + 0x900);
      if (iVar3 == *(int *)(param_1 + 0x65c)) {
        return uVar5;
      }
      piVar1 = (int *)(iVar4 + 0x92c);
      iVar4 = iVar4 + 0x30;
    } while (*piVar1 == 0x17);
  }
  return uVar5;
}

