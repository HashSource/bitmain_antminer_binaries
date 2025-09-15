
void pkey_gost_mac_cleanup(EVP_PKEY_CTX *param_1)

{
  void *ptr;
  
  ptr = EVP_PKEY_CTX_get_data(param_1);
  CRYPTO_free(ptr);
  return;
}

