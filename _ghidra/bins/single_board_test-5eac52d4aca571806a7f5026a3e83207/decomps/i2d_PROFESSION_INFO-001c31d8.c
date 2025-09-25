
void i2d_PROFESSION_INFO(ASN1_VALUE *param_1,uchar **param_2)

{
  ASN1_item_i2d(param_1,param_2,(ASN1_ITEM *)PROFESSION_INFO_it);
  return;
}

