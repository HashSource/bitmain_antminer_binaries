
void GOST_CIPHER_PARAMS_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)GOST_CIPHER_PARAMS_it);
  return;
}

