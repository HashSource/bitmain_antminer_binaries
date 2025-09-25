
undefined4 ssl3_release_write_buffer(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x660);
  if (iVar2 != 0) {
    iVar1 = param_1 + iVar2 * 0x14;
    do {
      iVar2 = iVar2 + -1;
      CRYPTO_free(*(void **)(iVar1 + 0x664));
      *(undefined4 *)(iVar1 + 0x664) = 0;
      iVar1 = iVar1 + -0x14;
    } while (iVar2 != 0);
  }
  *(undefined4 *)(param_1 + 0x660) = 0;
  return 1;
}

