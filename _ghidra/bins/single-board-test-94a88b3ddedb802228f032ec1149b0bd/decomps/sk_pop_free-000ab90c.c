
void sk_pop_free(_STACK *st,func *func)

{
  char **ppcVar1;
  char **ptr;
  int iVar2;
  int iVar3;
  
  if (st == (_STACK *)0x0) {
    return;
  }
  iVar3 = st->num;
  ptr = st->data;
  if (0 < iVar3) {
    iVar2 = 0;
    do {
      ppcVar1 = ptr + iVar2;
      iVar2 = iVar2 + 1;
      if (*ppcVar1 != (char *)0x0) {
        (*func)(*ppcVar1);
        ptr = st->data;
        iVar3 = st->num;
      }
    } while (iVar2 < iVar3);
  }
  if (ptr != (char **)0x0) {
    CRYPTO_free(ptr);
  }
  CRYPTO_free(st);
  return;
}

