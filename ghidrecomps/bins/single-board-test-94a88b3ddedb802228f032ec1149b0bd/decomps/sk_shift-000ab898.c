
void * sk_shift(_STACK *st)

{
  char **ppcVar1;
  int in_r1;
  char **ppcVar2;
  int in_r3;
  int iVar3;
  char *pcVar4;
  
  if (st == (_STACK *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else if (st->num < 1) {
    pcVar4 = (char *)0x0;
  }
  else {
    ppcVar2 = st->data;
    iVar3 = st->num + -1;
    if (iVar3 != 0) {
      in_r1 = 4;
      in_r3 = 0;
    }
    pcVar4 = *ppcVar2;
    if (iVar3 != 0) {
      while( true ) {
        ppcVar1 = (char **)((int)ppcVar2 + in_r1);
        in_r1 = in_r1 + 4;
        ppcVar2[in_r3] = *ppcVar1;
        in_r3 = in_r3 + 1;
        if (iVar3 <= in_r3) break;
        ppcVar2 = st->data;
      }
    }
    st->num = iVar3;
  }
  return pcVar4;
}

