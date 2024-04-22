
void lh_doall(_LHASH *lh,LHASH_DOALL_FN_TYPE func)

{
  void *pvVar1;
  void **ppvVar2;
  int iVar3;
  int iVar4;
  
  if (lh != (_LHASH *)0x0) {
    iVar4 = lh->num_nodes - 1;
    if (-1 < iVar4) {
      iVar3 = (lh->num_nodes + 0x3fffffff) * 4;
      do {
        ppvVar2 = *(void ***)((int)lh->b + iVar3);
        while (ppvVar2 != (void **)0x0) {
          pvVar1 = *ppvVar2;
          ppvVar2 = (void **)ppvVar2[1];
          (*func)(pvVar1);
        }
        iVar4 = iVar4 + -1;
        iVar3 = iVar3 + -4;
      } while (-1 < iVar4);
      return;
    }
  }
  return;
}

