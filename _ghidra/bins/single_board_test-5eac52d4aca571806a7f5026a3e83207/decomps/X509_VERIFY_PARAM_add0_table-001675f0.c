
int X509_VERIFY_PARAM_add0_table(X509_VERIFY_PARAM *param)

{
  int iVar1;
  X509_VERIFY_PARAM *param_00;
  
  if (param_table == 0) {
    param_table = OPENSSL_sk_new(0x166f59);
    if (param_table == 0) {
      return 0;
    }
  }
  else {
    iVar1 = OPENSSL_sk_find(param_table,param);
    if (-1 < iVar1) {
      param_00 = (X509_VERIFY_PARAM *)OPENSSL_sk_delete(param_table);
      X509_VERIFY_PARAM_free(param_00);
    }
  }
  iVar1 = OPENSSL_sk_push(param_table,param);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

