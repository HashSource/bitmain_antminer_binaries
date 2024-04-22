
void lh_doall_arg(_LHASH *lh,LHASH_DOALL_ARG_FN_TYPE func,void *arg)

{
  void **ppvVar1;
  void **ppvVar2;
  int iVar3;
  int iVar4;
  
  if (lh != (_LHASH *)0x0) {
    iVar4 = lh->num_nodes - 1;
    if (-1 < iVar4) {
      iVar3 = (lh->num_nodes + 0x3fffffff) * 4;
      do {
        ppvVar1 = *(void ***)((int)lh->b + iVar3);
        while (ppvVar1 != (void **)0x0) {
          ppvVar2 = (void **)ppvVar1[1];
          (*func)(*ppvVar1,arg);
          ppvVar1 = ppvVar2;
        }
        iVar4 = iVar4 + -1;
        iVar3 = iVar3 + -4;
      } while (-1 < iVar4);
      return;
    }
  }
  return;
}

