
int OSSL_STORE_INFO_get1_PKEY(int *param_1)

{
  if (*param_1 == 3) {
    EVP_PKEY_up_ref(param_1[1]);
    return param_1[1];
  }
  ERR_put_error(0x2c,0x69,0x66,"crypto/store/store_lib.c",0x193);
  return 0;
}

