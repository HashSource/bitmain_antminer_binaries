
int X509_PURPOSE_get_by_sname(char *sname)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  puVar4 = &xstandard;
  iVar3 = 0;
  while( true ) {
    if (xptable == (_STACK *)0x0) {
      if (8 < iVar3) {
        return -1;
      }
    }
    else {
      iVar2 = sk_num(xptable);
      if (iVar2 + 9 <= iVar3) {
        return -1;
      }
    }
    if (iVar3 < 0) {
      puVar1 = (undefined1 *)0x0;
    }
    else {
      puVar1 = puVar4;
      if (8 < iVar3) {
        puVar1 = (undefined1 *)sk_value(xptable,iVar3 + -9);
      }
    }
    puVar4 = puVar4 + 0x1c;
    iVar2 = strcmp(*(char **)(puVar1 + 0x14),sname);
    if (iVar2 == 0) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

