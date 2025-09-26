
int EVP_PKEY_meth_add0(EVP_PKEY_METHOD *pmeth)

{
  int iVar1;
  
  if (app_pkey_methods == 0) {
    app_pkey_methods = OPENSSL_sk_new(0x13cc85,pmeth);
    if (app_pkey_methods == 0) {
      iVar1 = 0x130;
      goto LAB_0013cdda;
    }
  }
  iVar1 = OPENSSL_sk_push(app_pkey_methods,pmeth);
  if (iVar1 != 0) {
    OPENSSL_sk_sort(app_pkey_methods);
    return 1;
  }
  iVar1 = 0x135;
LAB_0013cdda:
  ERR_put_error(6,0xc2,0x41,"crypto/evp/pmeth_lib.c",iVar1);
  return 0;
}

