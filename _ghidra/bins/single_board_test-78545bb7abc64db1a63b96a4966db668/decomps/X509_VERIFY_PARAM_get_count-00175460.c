
int X509_VERIFY_PARAM_get_count(void)

{
  int iVar1;
  
  if (param_table != 0) {
    iVar1 = OPENSSL_sk_num();
    return iVar1 + 5;
  }
  return 5;
}

