
undefined4 gost_control_func(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (param_2 == 200) {
    pcVar1 = getenv("CRYPT_PARAMS");
    if (pcVar1 != (char *)0x0) {
      param_4 = pcVar1;
    }
    if (gost_params != (char *)0x0) {
      CRYPTO_free(gost_params);
    }
    gost_params = BUF_strdup(param_4);
    uVar2 = 1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

