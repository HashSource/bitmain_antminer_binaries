
void pkey_hmac_cleanup(EVP_PKEY_CTX *param_1)

{
  void *ptr;
  
  ptr = EVP_PKEY_CTX_get_data(param_1);
  if (ptr != (void *)0x0) {
    HMAC_CTX_free(*(undefined4 *)((int)ptr + 0x14));
    CRYPTO_clear_free(*(undefined4 *)((int)ptr + 0xc),*(undefined4 *)((int)ptr + 4),
                      "crypto/hmac/hm_pmeth.c",0x50);
    CRYPTO_free(ptr);
    EVP_PKEY_CTX_set_data(param_1,(void *)0x0);
    return;
  }
  return;
}

