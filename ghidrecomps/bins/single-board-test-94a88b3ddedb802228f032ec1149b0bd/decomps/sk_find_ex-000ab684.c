
int sk_find_ex(_STACK *st,void *data)

{
  void *pvVar1;
  int iVar2;
  char **ppcVar3;
  void *local_14;
  
  if (st != (_STACK *)0x0) {
    if (st->comp == (_func_290 *)0x0) {
      if (0 < st->num) {
        ppcVar3 = st->data;
        iVar2 = 0;
        if ((char *)data == *ppcVar3) {
          return 0;
        }
        while (iVar2 = iVar2 + 1, iVar2 != st->num) {
          ppcVar3 = ppcVar3 + 1;
          if ((char *)data == *ppcVar3) {
            return iVar2;
          }
        }
      }
    }
    else {
      local_14 = data;
      if (st->sorted == 0) {
        qsort(st->data,st->num,4,(__compar_fn_t)st->comp);
        st->sorted = 1;
      }
      if ((local_14 != (void *)0x0) &&
         (pvVar1 = OBJ_bsearch_ex_(&local_14,st->data,st->num,4,(cmp *)st->comp,1),
         pvVar1 != (void *)0x0)) {
        return (int)pvVar1 - (int)st->data >> 2;
      }
    }
  }
  return -1;
}

