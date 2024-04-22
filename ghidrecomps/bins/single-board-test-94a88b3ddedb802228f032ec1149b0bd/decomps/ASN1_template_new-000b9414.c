
int ASN1_template_new(ASN1_VALUE **pval,ASN1_TEMPLATE *tt)

{
  int iVar1;
  _STACK *p_Var2;
  uint uVar3;
  
  uVar3 = tt->flags;
  if ((uVar3 & 1) == 0) {
    if ((uVar3 & 0x300) == 0) {
      if ((uVar3 & 6) == 0) {
        iVar1 = asn1_item_ex_combine_new(pval,tt->item,uVar3 & 0x400);
        return iVar1;
      }
      p_Var2 = sk_new_null();
      if (p_Var2 == (_STACK *)0x0) {
        ERR_put_error(0xd,0x85,0x41,DAT_000b9484,0x115);
        iVar1 = 0;
      }
      else {
        *pval = (ASN1_VALUE *)p_Var2;
        iVar1 = 1;
      }
    }
    else {
      *pval = (ASN1_VALUE *)0x0;
      iVar1 = 1;
    }
  }
  else if ((uVar3 & 0x306) == 0) {
    asn1_item_clear(pval,tt->item);
    iVar1 = 1;
  }
  else {
    iVar1 = 1;
    *pval = (ASN1_VALUE *)0x0;
  }
  return iVar1;
}

