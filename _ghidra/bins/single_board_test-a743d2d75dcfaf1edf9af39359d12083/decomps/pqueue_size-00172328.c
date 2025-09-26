
int pqueue_size(pqueue pq)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)pq;
  if (iVar2 != 0) {
    iVar1 = 0;
    do {
      iVar2 = *(int *)(iVar2 + 0xc);
      iVar1 = iVar1 + 1;
    } while (iVar2 != 0);
    return iVar1;
  }
  return 0;
}

