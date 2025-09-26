
void i2d_SCRYPT_PARAMS(ASN1_VALUE *param_1,uchar **param_2)

{
  ASN1_item_i2d(param_1,param_2,(ASN1_ITEM *)&SCRYPT_PARAMS_it);
  return;
}

