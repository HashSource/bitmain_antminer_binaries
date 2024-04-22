
int EVP_PKEY_asn1_add0(EVP_PKEY_ASN1_METHOD *ameth)

{
  _STACK **pp_Var1;
  _STACK *st;
  int iVar2;
  
  pp_Var1 = DAT_000bc090;
  st = *DAT_000bc090;
  if (st == (_STACK *)0x0) {
    st = sk_new(DAT_000bc094);
    *pp_Var1 = st;
    if (st == (_STACK *)0x0) {
      return 0;
    }
  }
  iVar2 = sk_push(st,ameth);
  if (iVar2 == 0) {
    return 0;
  }
  sk_sort(*pp_Var1);
  return 1;
}

