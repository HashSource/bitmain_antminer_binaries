
undefined4 X509_VERIFY_PARAM_set1_email(int param_1,char *param_2,size_t param_3)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x20);
  if (param_2 == (char *)0x0) {
    param_3 = 0;
    pcVar1 = (char *)0x0;
  }
  else {
    if (param_3 == 0) {
      pcVar1 = BUF_strdup(param_2);
      param_3 = strlen(param_2);
    }
    else {
      pcVar1 = (char *)BUF_memdup(param_2,param_3);
    }
    if (pcVar1 == (char *)0x0) {
      return 0;
    }
  }
  if (*(void **)(iVar2 + 0xc) != (void *)0x0) {
    CRYPTO_free(*(void **)(iVar2 + 0xc));
  }
  *(char **)(iVar2 + 0xc) = pcVar1;
  if (iVar2 != -0x10) {
    *(size_t *)(iVar2 + 0x10) = param_3;
    return 1;
  }
  return 1;
}

