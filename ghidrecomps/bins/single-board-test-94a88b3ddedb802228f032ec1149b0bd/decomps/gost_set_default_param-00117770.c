
undefined4 gost_set_default_param(int param_1,char *param_2)

{
  char **ppcVar1;
  char *pcVar2;
  char *ptr;
  
  ppcVar1 = DAT_001177a4;
  if (param_1 != 0) {
    return 0;
  }
  pcVar2 = getenv(DAT_001177a8);
  ptr = *ppcVar1;
  if (pcVar2 != (char *)0x0) {
    param_2 = pcVar2;
  }
  if (ptr != (char *)0x0) {
    CRYPTO_free(ptr);
  }
  pcVar2 = BUF_strdup(param_2);
  *ppcVar1 = pcVar2;
  return 1;
}

