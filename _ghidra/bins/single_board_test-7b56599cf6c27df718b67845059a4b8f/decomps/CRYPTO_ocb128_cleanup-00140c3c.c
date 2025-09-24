
void CRYPTO_ocb128_cleanup(void *param_1)

{
  if (param_1 != (void *)0x0) {
    CRYPTO_clear_free(*(undefined4 *)((int)param_1 + 0x40),*(int *)((int)param_1 + 0x18) << 4,
                      "crypto/modes/ocb128.c",0x22d);
    OPENSSL_cleanse(param_1,0x98);
    return;
  }
  return;
}

