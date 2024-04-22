
void i2d_re_X509_tbs(ASN1_VALUE **param_1,uchar **param_2)

{
  ASN1_VALUE *val;
  
  val = *param_1;
  *(undefined4 *)(val + 0x30) = 1;
  ASN1_item_i2d(val,param_2,(ASN1_ITEM *)&X509_CINF_it);
  return;
}

