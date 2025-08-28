
void i2d_GOST_CLIENT_KEY_EXCHANGE_PARAMS(ASN1_VALUE *param_1,uchar **param_2)

{
  ASN1_item_i2d(param_1,param_2,(ASN1_ITEM *)GOST_CLIENT_KEY_EXCHANGE_PARAMS_it);
  return;
}

