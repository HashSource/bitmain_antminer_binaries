
int EVP_PKEY_get0_DSA(int *param_1)

{
  if (*param_1 == 0x74) {
    return param_1[6];
  }
  ERR_put_error(6,0x78,0x81,"crypto/evp/p_lib.c",0x1f5);
  return 0;
}

