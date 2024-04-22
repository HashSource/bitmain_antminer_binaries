
int EVP_PKEY_meth_add0(EVP_PKEY_METHOD *pmeth)

{
  _STACK **pp_Var1;
  _STACK *st;
  int iVar2;
  
  pp_Var1 = DAT_000b3cd0;
  st = *DAT_000b3cd0;
  if (st == (_STACK *)0x0) {
    st = sk_new(DAT_000b3cd4);
    *pp_Var1 = st;
    if (st == (_STACK *)0x0) {
      return 0;
    }
  }
  iVar2 = sk_push(st,pmeth);
  if (iVar2 == 0) {
    return 0;
  }
  sk_sort(*pp_Var1);
  return 1;
}

