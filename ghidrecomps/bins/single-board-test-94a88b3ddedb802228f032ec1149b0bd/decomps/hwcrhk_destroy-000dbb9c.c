
undefined4 hwcrhk_destroy(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_000dbbdc;
  if (*(void **)(DAT_000dbbdc + 0x18) != (void *)0x0) {
    CRYPTO_free(*(void **)(DAT_000dbbdc + 0x18));
  }
  iVar2 = DAT_000dbbe0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  iVar1 = DAT_000dbbdc;
  if (*(int *)(iVar2 + 0x58) == 0) {
    ERR_unload_strings(*(int *)(DAT_000dbbdc + 0x1c),(ERR_STRING_DATA *)(iVar2 + 0x5c));
    ERR_unload_strings(*(int *)(iVar1 + 0x1c),(ERR_STRING_DATA *)(iVar2 + 0xb4));
    ERR_unload_strings(0,(ERR_STRING_DATA *)(iVar2 + 300));
    *(undefined4 *)(iVar2 + 0x58) = 1;
  }
  return 1;
}

