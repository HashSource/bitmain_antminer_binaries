
void pkey_hmac_cleanup(int param_1)

{
  void *ptr;
  void *ptr_00;
  
  ptr_00 = *(void **)(param_1 + 0x14);
  HMAC_CTX_cleanup((HMAC_CTX *)((int)ptr_00 + 0x14));
  ptr = *(void **)((int)ptr_00 + 0xc);
  if (ptr != (void *)0x0) {
    if (*(size_t *)((int)ptr_00 + 4) != 0) {
      OPENSSL_cleanse(ptr,*(size_t *)((int)ptr_00 + 4));
      ptr = *(void **)((int)ptr_00 + 0xc);
    }
    CRYPTO_free(ptr);
    *(undefined4 *)((int)ptr_00 + 0xc) = 0;
  }
  CRYPTO_free(ptr_00);
  return;
}

