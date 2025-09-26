
void ssl_clear_cipher_ctx(int param_1)

{
  if (*(EVP_CIPHER_CTX **)(param_1 + 0x80) != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_cleanup(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
    CRYPTO_free(*(void **)(param_1 + 0x80));
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if (*(EVP_CIPHER_CTX **)(param_1 + 0x8c) != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_cleanup(*(EVP_CIPHER_CTX **)(param_1 + 0x8c));
    CRYPTO_free(*(void **)(param_1 + 0x8c));
    *(undefined4 *)(param_1 + 0x8c) = 0;
  }
  if (*(COMP_CTX **)(param_1 + 0x88) != (COMP_CTX *)0x0) {
    COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  if (*(COMP_CTX **)(param_1 + 0x94) != (COMP_CTX *)0x0) {
    COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x94));
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  return;
}

