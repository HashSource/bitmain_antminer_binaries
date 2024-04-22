
undefined4 atalla_destroy(void)

{
  void **ppvVar1;
  int *piVar2;
  
  ppvVar1 = DAT_000da0f4;
  if (*DAT_000da0f4 != (void *)0x0) {
    CRYPTO_free(*DAT_000da0f4);
  }
  piVar2 = DAT_000da0f8;
  *ppvVar1 = (void *)0x0;
  ppvVar1 = DAT_000da0f4;
  if (*piVar2 == 0) {
    ERR_unload_strings((int)DAT_000da0f4[1],(ERR_STRING_DATA *)(piVar2 + 1));
    ERR_unload_strings((int)ppvVar1[1],(ERR_STRING_DATA *)(piVar2 + 0xd));
    ERR_unload_strings(0,(ERR_STRING_DATA *)(piVar2 + 0x1f));
    *piVar2 = 1;
  }
  return 1;
}

