
int EVP_PKEY_meth_get_count(void)

{
  int iVar1;
  
  if (app_pkey_methods != 0) {
    iVar1 = OPENSSL_sk_num();
    return iVar1 + 0x12;
  }
  return 0x12;
}

