
void pkey_gost_cleanup(EVP_PKEY_CTX *param_1)

{
  void *ptr;
  
  ptr = EVP_PKEY_CTX_get_data(param_1);
  if (*(void **)((int)ptr + 8) != (void *)0x0) {
    CRYPTO_free(*(void **)((int)ptr + 8));
  }
  CRYPTO_free(ptr);
  return;
}

