
void i2d_re_X509_REQ_tbs(X509_REQ_INFO *param_1,uchar **param_2)

{
  (param_1->enc).modified = 1;
  i2d_X509_REQ_INFO(param_1,param_2);
  return;
}

