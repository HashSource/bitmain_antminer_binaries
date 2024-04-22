
undefined4 cswift_destroy(void)

{
  void **ppvVar1;
  int *piVar2;
  
  ppvVar1 = DAT_000da7b0;
  if (*DAT_000da7b0 != (void *)0x0) {
    CRYPTO_free(*DAT_000da7b0);
  }
  piVar2 = DAT_000da7b4;
  *ppvVar1 = (void *)0x0;
  ppvVar1 = DAT_000da7b0;
  if (*piVar2 == 0) {
    ERR_unload_strings((int)DAT_000da7b0[1],(ERR_STRING_DATA *)(piVar2 + 1));
    ERR_unload_strings((int)ppvVar1[1],(ERR_STRING_DATA *)(piVar2 + 0x15));
    ERR_unload_strings(0,(ERR_STRING_DATA *)(piVar2 + 0x29));
    *piVar2 = 1;
  }
  return 1;
}

