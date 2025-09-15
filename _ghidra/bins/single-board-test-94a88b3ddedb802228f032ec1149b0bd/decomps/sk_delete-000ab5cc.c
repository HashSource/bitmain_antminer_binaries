
void * sk_delete(_STACK *st,int loc)

{
  int iVar1;
  char *pcVar2;
  char **ppcVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = 1 - (int)st;
  if ((_STACK *)0x1 < st) {
    iVar1 = 0;
  }
  if (iVar1 == 0 && -1 < loc) {
    pcVar2 = (char *)0x0;
    if (loc < st->num) {
      ppcVar3 = st->data;
      iVar5 = st->num + -1;
      iVar1 = loc << 2;
      pcVar2 = ppcVar3[loc];
      if ((iVar5 != loc) && (loc < iVar5)) {
        while( true ) {
          puVar4 = (undefined4 *)((int)ppcVar3 + iVar1);
          iVar1 = iVar1 + 4;
          loc = loc + 1;
          *puVar4 = *(undefined4 *)((int)ppcVar3 + iVar1);
          if (iVar5 == loc) break;
          ppcVar3 = st->data;
        }
      }
      st->num = iVar5;
    }
  }
  else {
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}

