
void ASN1_item_free(ASN1_VALUE *val,ASN1_ITEM *it)

{
  ASN1_VALUE *local_c [3];
  
  local_c[0] = val;
  asn1_item_combine_free(local_c,it,0);
  return;
}

