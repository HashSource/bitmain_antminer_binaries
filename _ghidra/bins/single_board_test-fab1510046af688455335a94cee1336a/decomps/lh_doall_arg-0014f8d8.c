
void lh_doall_arg(_LHASH *lh,LHASH_DOALL_ARG_FN_TYPE func,void *arg)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (lh != (_LHASH *)0x0) {
    iVar4 = lh->num_nodes - 1;
    if (-1 < iVar4) {
      iVar3 = (lh->num_nodes + 0x3fffffff) * 4;
      do {
        puVar1 = *(undefined4 **)((int)lh->b + iVar3);
        while (puVar1 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)puVar1[1];
          (*func)((void *)*puVar1,arg);
          puVar1 = puVar2;
        }
        iVar4 = iVar4 + -1;
        iVar3 = iVar3 + -4;
      } while (-1 < iVar4);
      return;
    }
  }
  return;
}

