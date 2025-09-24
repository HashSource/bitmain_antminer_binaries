
undefined4 drbg_ctr_uninstantiate(int param_1)

{
  EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(param_1 + 100));
  EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(param_1 + 0x68));
  EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(param_1 + 0x6c));
  OPENSSL_cleanse((void *)(param_1 + 100),0x8c);
  return 1;
}

