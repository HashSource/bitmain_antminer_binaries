
int X509V3_EXT_add(X509V3_EXT_METHOD *ext)

{
  _STACK **pp_Var1;
  int iVar2;
  _STACK *st;
  
  pp_Var1 = DAT_000c65cc;
  st = *DAT_000c65cc;
  if (st == (_STACK *)0x0) {
    st = sk_new(DAT_000c65d4);
    *pp_Var1 = st;
    iVar2 = 0x4d;
    if (st == (_STACK *)0x0) goto LAB_000c65a2;
  }
  iVar2 = sk_push(st,ext);
  if (iVar2 != 0) {
    return 1;
  }
  iVar2 = 0x51;
LAB_000c65a2:
  ERR_put_error(0x22,0x68,0x41,DAT_000c65d0,iVar2);
  return 0;
}

