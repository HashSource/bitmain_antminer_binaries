
void pkey_tls1_prf_cleanup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *ptr;
  
  ptr = *(void **)(param_1 + 0x14);
  CRYPTO_clear_free(*(undefined4 *)((int)ptr + 4),*(undefined4 *)((int)ptr + 8),
                    "crypto/kdf/tls1_prf.c",0x34,param_4);
  OPENSSL_cleanse((void *)((int)ptr + 0xc),*(size_t *)((int)ptr + 0x40c));
  CRYPTO_free(ptr);
  return;
}

