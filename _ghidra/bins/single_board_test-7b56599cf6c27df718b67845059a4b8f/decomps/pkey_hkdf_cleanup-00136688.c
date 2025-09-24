
void pkey_hkdf_cleanup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *ptr;
  
  ptr = *(void **)(param_1 + 0x14);
  CRYPTO_clear_free(*(undefined4 *)((int)ptr + 8),*(undefined4 *)((int)ptr + 0xc),
                    "crypto/kdf/hkdf.c",0x40,param_4);
  CRYPTO_clear_free(*(undefined4 *)((int)ptr + 0x10),*(undefined4 *)((int)ptr + 0x14),
                    "crypto/kdf/hkdf.c",0x41);
  OPENSSL_cleanse((void *)((int)ptr + 0x18),*(size_t *)((int)ptr + 0x418));
  CRYPTO_free(ptr);
  return;
}

