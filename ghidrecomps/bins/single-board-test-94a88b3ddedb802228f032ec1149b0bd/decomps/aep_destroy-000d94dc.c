
undefined4 aep_destroy(void)

{
  void **ppvVar1;
  int *piVar2;
  
  ppvVar1 = DAT_000d9510;
  if (*DAT_000d9510 != (void *)0x0) {
    CRYPTO_free(*DAT_000d9510);
  }
  piVar2 = DAT_000d9514;
  *ppvVar1 = (void *)0x0;
  ppvVar1 = DAT_000d9510;
  if (*piVar2 == 0) {
    ERR_unload_strings((int)DAT_000d9510[1],(ERR_STRING_DATA *)(piVar2 + 1));
    ERR_unload_strings((int)ppvVar1[1],(ERR_STRING_DATA *)(piVar2 + 0x13));
    *piVar2 = 1;
  }
  return 1;
}

