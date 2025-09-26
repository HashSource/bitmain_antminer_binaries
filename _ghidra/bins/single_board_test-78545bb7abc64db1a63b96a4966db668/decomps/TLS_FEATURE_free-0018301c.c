
void TLS_FEATURE_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)&TLS_FEATURE_it);
  return;
}

