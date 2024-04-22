
void * sk_delete(_STACK *st,int loc)

{
  uint uVar1;
  char *pcVar2;
  char **ppcVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  uVar1 = 1 - (int)st;
  if ((_STACK *)0x1 < st) {
    uVar1 = 0;
  }
  if ((uVar1 | (uint)loc >> 0x1f) == 0) {
    pcVar2 = (char *)0x0;
    if (loc < st->num) {
      ppcVar3 = st->data;
      iVar6 = st->num + -1;
      iVar4 = loc << 2;
      pcVar2 = ppcVar3[loc];
      if ((iVar6 != loc) && (loc < iVar6)) {
        while( true ) {
          puVar5 = (undefined4 *)((int)ppcVar3 + iVar4);
          iVar4 = iVar4 + 4;
          loc = loc + 1;
          *puVar5 = *(undefined4 *)((int)ppcVar3 + iVar4);
          if (iVar6 == loc) break;
          ppcVar3 = st->data;
        }
      }
      st->num = iVar6;
    }
  }
  else {
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}

