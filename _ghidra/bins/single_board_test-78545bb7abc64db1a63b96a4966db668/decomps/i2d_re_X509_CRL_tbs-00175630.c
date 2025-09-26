
void i2d_re_X509_CRL_tbs(X509_CRL_INFO *param_1,uchar **param_2)

{
  param_1[1].version = (ASN1_INTEGER *)0x1;
  i2d_X509_CRL_INFO(param_1,param_2);
  return;
}

