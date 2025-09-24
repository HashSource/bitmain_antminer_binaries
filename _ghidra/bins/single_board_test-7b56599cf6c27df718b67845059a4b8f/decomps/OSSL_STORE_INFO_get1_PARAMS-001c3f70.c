
int OSSL_STORE_INFO_get1_PARAMS(int *param_1)

{
  if (*param_1 == 2) {
    EVP_PKEY_up_ref(param_1[1]);
    return param_1[1];
  }
  ERR_put_error(0x2c,0x68,0x68,"crypto/store/store_lib.c",0x181);
  return 0;
}

