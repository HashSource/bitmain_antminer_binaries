
int X509V3_EXT_add_list(X509V3_EXT_METHOD *extlist)

{
  _STACK **pp_Var1;
  _STACK *st;
  int iVar2;
  
  pp_Var1 = DAT_000c6770;
  iVar2 = extlist->ext_nid;
  while( true ) {
    if (iVar2 == -1) {
      return 1;
    }
    st = *pp_Var1;
    if (st == (_STACK *)0x0) {
      st = sk_new(DAT_000c6778);
      *pp_Var1 = st;
      if (st == (_STACK *)0x0) {
        iVar2 = 0x4d;
        goto LAB_000c674a;
      }
    }
    iVar2 = sk_push(st,extlist);
    if (iVar2 == 0) break;
    iVar2 = extlist[1].ext_nid;
    HintPreloadData(extlist + 7);
    extlist = extlist + 1;
  }
  iVar2 = 0x51;
LAB_000c674a:
  ERR_put_error(0x22,0x68,0x41,DAT_000c6774,iVar2);
  return 0;
}

