
undefined4 SSL_has_pending(int param_1)

{
  pitem *ppVar1;
  int iVar2;
  undefined4 uVar3;
  pitem *local_14 [2];
  
  if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
    local_14[0] = pqueue_iterator(*(pqueue *)(*(int *)(param_1 + 0xf38) + 0x30));
    do {
      ppVar1 = pqueue_next(local_14);
      if (ppVar1 == (pitem *)0x0) goto LAB_000dc1ce;
    } while (*(int *)((int)ppVar1->data + 0x24) == 0);
  }
  else {
LAB_000dc1ce:
    iVar2 = RECORD_LAYER_processed_read_pending(param_1 + 0x650);
    if (iVar2 == 0) {
      uVar3 = RECORD_LAYER_read_pending(param_1 + 0x650);
      return uVar3;
    }
  }
  return 1;
}

