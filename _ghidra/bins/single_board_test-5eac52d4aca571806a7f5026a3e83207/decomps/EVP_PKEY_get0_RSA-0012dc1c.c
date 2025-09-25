
int EVP_PKEY_get0_RSA(int *param_1)

{
  if (*param_1 == 6 || *param_1 == 0x390) {
    return param_1[6];
  }
  ERR_put_error(6,0x79,0x7f,"crypto/evp/p_lib.c",0x1da);
  return 0;
}

