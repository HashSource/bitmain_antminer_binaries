
int OSSL_STORE_INFO_get1_CERT(int *param_1)

{
  if (*param_1 == 4) {
    X509_up_ref(param_1[1]);
    return param_1[1];
  }
  ERR_put_error(0x2c,0x65,100,"crypto/store/store_lib.c",0x1a5);
  return 0;
}

