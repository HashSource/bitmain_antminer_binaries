
undefined4 X509_VERIFY_PARAM_set1_ip(int param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  pcVar1 = param_2;
  if (((uint)param_3 & 0xfffffffb) == 0) {
    iVar2 = *(int *)(param_1 + 0x20);
    iVar3 = iVar2 + 0x18;
    if (param_2 == (char *)0x0) goto LAB_000c6372;
    if (param_3 != (char *)0x0) goto LAB_000c6392;
    pcVar1 = BUF_strdup(param_2);
    param_3 = (char *)strlen(param_2);
  }
  else {
    if (param_3 != (char *)0x10) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x20);
    iVar3 = iVar2 + 0x18;
    if (param_2 == (char *)0x0) goto LAB_000c6372;
LAB_000c6392:
    pcVar1 = (char *)BUF_memdup(param_2,(size_t)param_3);
  }
  param_2 = param_3;
  if (pcVar1 == (char *)0x0) {
    return 0;
  }
LAB_000c6372:
  if (*(void **)(iVar2 + 0x14) != (void *)0x0) {
    CRYPTO_free(*(void **)(iVar2 + 0x14));
  }
  *(char **)(iVar2 + 0x14) = pcVar1;
  if (iVar3 != 0) {
    *(char **)(iVar2 + 0x18) = param_2;
    return 1;
  }
  return 1;
}

