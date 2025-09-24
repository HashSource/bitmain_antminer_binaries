
undefined4 OSSL_STORE_INFO_set0_NAME_description(int *param_1,int param_2)

{
  if (*param_1 == 1) {
    param_1[2] = param_2;
    return 1;
  }
  ERR_put_error(0x2c,0x86,7,"crypto/store/store_lib.c",0x10e);
  return 0;
}

