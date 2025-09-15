
void GOST_CLIENT_KEY_EXCHANGE_PARAMS_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)GOST_CLIENT_KEY_EXCHANGE_PARAMS_it);
  return;
}

