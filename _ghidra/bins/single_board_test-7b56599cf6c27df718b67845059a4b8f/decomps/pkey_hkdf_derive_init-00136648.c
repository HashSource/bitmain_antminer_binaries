
undefined4
pkey_hkdf_derive_init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *__s;
  
  __s = *(void **)(param_1 + 0x14);
  CRYPTO_clear_free(*(undefined4 *)((int)__s + 0x10),*(undefined4 *)((int)__s + 0x14),
                    "crypto/kdf/hkdf.c",0xb6,param_4);
  CRYPTO_clear_free(*(undefined4 *)((int)__s + 8),*(undefined4 *)((int)__s + 0xc),
                    "crypto/kdf/hkdf.c",0xb7);
  OPENSSL_cleanse((void *)((int)__s + 0x18),*(size_t *)((int)__s + 0x418));
  memset(__s,0,0x41c);
  return 1;
}

