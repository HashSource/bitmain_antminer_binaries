
undefined4 X509_VERIFY_PARAM_set1_email(int param_1,char *param_2,size_t param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 == (char *)0x0) {
    iVar1 = 0;
    param_3 = 0;
  }
  else {
    if (param_3 == 0) {
      param_3 = strlen(param_2);
    }
    iVar1 = CRYPTO_memdup(param_2,param_3,"crypto/x509/x509_vpm.c",0xf7,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  CRYPTO_free(*(void **)(param_1 + 0x30));
  *(int *)(param_1 + 0x30) = iVar1;
  if (param_1 != -0x34) {
    *(size_t *)(param_1 + 0x34) = param_3;
    return 1;
  }
  return 1;
}

