
void OSSL_STORE_INFO_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    switch(*param_1) {
    case 1:
      CRYPTO_free((void *)param_1[1]);
      CRYPTO_free((void *)param_1[2]);
      break;
    case 2:
    case 3:
      EVP_PKEY_free((EVP_PKEY *)param_1[1]);
      break;
    case 4:
      X509_free((X509 *)param_1[1]);
      break;
    case 5:
      X509_CRL_free((X509_CRL *)param_1[1]);
      break;
    case 0xffffffff:
      BUF_MEM_free((BUF_MEM *)param_1[1]);
      CRYPTO_free((void *)param_1[2]);
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

