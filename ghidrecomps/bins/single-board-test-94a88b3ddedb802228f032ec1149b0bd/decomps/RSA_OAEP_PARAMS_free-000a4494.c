
void RSA_OAEP_PARAMS_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)RSA_OAEP_PARAMS_it);
  return;
}

