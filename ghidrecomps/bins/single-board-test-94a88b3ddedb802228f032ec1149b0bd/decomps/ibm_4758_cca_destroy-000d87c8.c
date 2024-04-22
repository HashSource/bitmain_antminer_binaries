
undefined4 ibm_4758_cca_destroy(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_000d8800;
  iVar1 = DAT_000d87fc;
  if (*(int *)(DAT_000d87fc + 4) == 0) {
    ERR_unload_strings(*(int *)(DAT_000d8800 + 0xc),(ERR_STRING_DATA *)(DAT_000d87fc + 8));
    ERR_unload_strings(*(int *)(iVar2 + 0xc),(ERR_STRING_DATA *)(iVar1 + 0x48));
    *(undefined4 *)(iVar1 + 4) = 1;
  }
  if (*(void **)(iVar2 + 0x10) != (void *)0x0) {
    CRYPTO_free(*(void **)(iVar2 + 0x10));
  }
  *(undefined4 *)(iVar2 + 0x10) = 0;
  return 1;
}

