
void * sk_pop(_STACK *st)

{
  char *pcVar1;
  int iVar2;
  
  if (st == (_STACK *)0x0) {
    return (void *)0x0;
  }
  if (0 < st->num) {
    iVar2 = st->num + -1;
    pcVar1 = st->data[iVar2];
    st->num = iVar2;
    return pcVar1;
  }
  return (void *)0x0;
}

