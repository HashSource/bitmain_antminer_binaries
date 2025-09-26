
int asn1_get_choice_selector(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  return *(int *)(*pval + it->utype);
}

