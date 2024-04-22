
undefined4 nuron_destroy(void)

{
  void **ppvVar1;
  int *piVar2;
  
  ppvVar1 = DAT_000dcbe0;
  if (*DAT_000dcbe0 != (void *)0x0) {
    CRYPTO_free(*DAT_000dcbe0);
  }
  piVar2 = DAT_000dcbe4;
  *ppvVar1 = (void *)0x0;
  ppvVar1 = DAT_000dcbe0;
  if (*piVar2 == 0) {
    ERR_unload_strings((int)DAT_000dcbe0[1],(ERR_STRING_DATA *)(piVar2 + 1));
    ERR_unload_strings((int)ppvVar1[1],(ERR_STRING_DATA *)(piVar2 + 0xb));
    ERR_unload_strings(0,(ERR_STRING_DATA *)(piVar2 + 0x19));
    *piVar2 = 1;
  }
  return 1;
}

