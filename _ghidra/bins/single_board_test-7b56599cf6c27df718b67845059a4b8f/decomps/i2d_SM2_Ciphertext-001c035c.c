
void i2d_SM2_Ciphertext(ASN1_VALUE *param_1,uchar **param_2)

{
  ASN1_item_i2d(param_1,param_2,(ASN1_ITEM *)&SM2_Ciphertext_it);
  return;
}

