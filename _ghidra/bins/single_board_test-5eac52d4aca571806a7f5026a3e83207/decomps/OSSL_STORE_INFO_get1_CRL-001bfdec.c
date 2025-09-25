
int OSSL_STORE_INFO_get1_CRL(int *param_1)

{
  if (*param_1 == 5) {
    X509_CRL_up_ref(param_1[1]);
    return param_1[1];
  }
  ERR_put_error(0x2c,0x66,0x65,"crypto/store/store_lib.c",0x1b7);
  return 0;
}

