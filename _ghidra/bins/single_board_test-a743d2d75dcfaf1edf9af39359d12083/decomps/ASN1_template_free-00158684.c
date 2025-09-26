
void ASN1_template_free(ASN1_VALUE **pval,ASN1_TEMPLATE *tt)

{
  int iVar1;
  int iVar2;
  _STACK *p_Var3;
  void *local_1c [2];
  
  if ((tt->flags & 6) == 0) {
    asn1_item_combine_free(pval,tt->item,tt->flags & 0x400);
  }
  else {
    p_Var3 = (_STACK *)*pval;
    iVar2 = 0;
    while( true ) {
      iVar1 = sk_num(p_Var3);
      if (iVar1 <= iVar2) break;
      local_1c[0] = sk_value(p_Var3,iVar2);
      asn1_item_combine_free(local_1c,tt->item,0);
      iVar2 = iVar2 + 1;
    }
    sk_free(p_Var3);
    *pval = (ASN1_VALUE *)0x0;
  }
  return;
}

