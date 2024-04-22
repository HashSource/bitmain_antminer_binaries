
undefined4 ubsec_destroy(void)

{
  void **ppvVar1;
  int *piVar2;
  
  ppvVar1 = DAT_000de290;
  if (*DAT_000de290 != (void *)0x0) {
    CRYPTO_free(*DAT_000de290);
  }
  piVar2 = DAT_000de294;
  *ppvVar1 = (void *)0x0;
  ppvVar1 = DAT_000de290;
  if (*piVar2 == 0) {
    ERR_unload_strings((int)DAT_000de290[1],(ERR_STRING_DATA *)(piVar2 + 1));
    ERR_unload_strings((int)ppvVar1[1],(ERR_STRING_DATA *)(piVar2 + 0x1b));
    ERR_unload_strings(0,(ERR_STRING_DATA *)(piVar2 + 0x2f));
    *piVar2 = 1;
  }
  return 1;
}

