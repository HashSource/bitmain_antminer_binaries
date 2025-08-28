
undefined4 gost_set_default_param(int param_1,char *param_2)

{
  char *pcVar1;
  
  if (param_1 != 0) {
    return 0;
  }
  pcVar1 = getenv("CRYPT_PARAMS");
  if (pcVar1 != (char *)0x0) {
    param_2 = pcVar1;
  }
  if (gost_params != (char *)0x0) {
    CRYPTO_free(gost_params);
  }
  gost_params = BUF_strdup(param_2);
  return 1;
}

