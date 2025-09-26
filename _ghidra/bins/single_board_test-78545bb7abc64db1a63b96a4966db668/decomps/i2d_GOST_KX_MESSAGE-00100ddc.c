
void i2d_GOST_KX_MESSAGE(ASN1_VALUE *param_1,uchar **param_2)

{
  ASN1_item_i2d(param_1,param_2,(ASN1_ITEM *)&GOST_KX_MESSAGE_it);
  return;
}

