
int asn1_set_choice_selector(ASN1_VALUE **pval,int value,ASN1_ITEM *it)

{
  int iVar1;
  
  iVar1 = *(int *)(*pval + it->utype);
  *(int *)(*pval + it->utype) = value;
  return iVar1;
}

