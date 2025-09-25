
void i2d_re_X509_tbs(X509_CINF *param_1,uchar **param_2)

{
  param_1[1].validity = (X509_VAL *)0x1;
  i2d_X509_CINF(param_1,param_2);
  return;
}

