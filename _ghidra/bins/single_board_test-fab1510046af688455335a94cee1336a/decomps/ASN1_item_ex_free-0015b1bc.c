
void ASN1_item_ex_free(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  asn1_item_combine_free(pval,it,0);
  return;
}

