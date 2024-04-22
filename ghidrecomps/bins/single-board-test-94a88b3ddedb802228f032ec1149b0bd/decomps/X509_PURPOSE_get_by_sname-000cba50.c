
int X509_PURPOSE_get_by_sname(char *sname)

{
  _STACK **pp_Var1;
  void *pvVar2;
  int iVar3;
  _STACK *p_Var4;
  int iVar5;
  void *pvVar6;
  
  pp_Var1 = DAT_000cbaa8;
  iVar5 = 0;
  pvVar6 = DAT_000cbaa4;
  while( true ) {
    p_Var4 = *pp_Var1;
    if (p_Var4 == (_STACK *)0x0) {
      if (8 < iVar5) {
        return -1;
      }
    }
    else {
      iVar3 = sk_num(p_Var4);
      if (iVar3 + 9 <= iVar5) {
        return -1;
      }
    }
    if (iVar5 < 0) {
      pvVar2 = (void *)0x0;
    }
    else {
      pvVar2 = pvVar6;
      if (8 < iVar5) {
        pvVar2 = sk_value(*pp_Var1,iVar5 + -9);
      }
    }
    pvVar6 = (void *)((int)pvVar6 + 0x1c);
    iVar3 = strcmp(*(char **)((int)pvVar2 + 0x14),sname);
    if (iVar3 == 0) break;
    iVar5 = iVar5 + 1;
  }
  return iVar5;
}

