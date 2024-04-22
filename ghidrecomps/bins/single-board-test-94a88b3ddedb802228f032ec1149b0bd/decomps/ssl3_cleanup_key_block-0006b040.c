
void ssl3_cleanup_key_block(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (*(void **)(iVar1 + 0x378) != (void *)0x0) {
    OPENSSL_cleanse(*(void **)(iVar1 + 0x378),*(size_t *)(iVar1 + 0x374));
    CRYPTO_free(*(void **)(*(int *)(param_1 + 0x58) + 0x378));
    iVar1 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar1 + 0x378) = 0;
  }
  *(undefined4 *)(iVar1 + 0x374) = 0;
  return;
}

