
void ssl_clear_cipher_ctx(int param_1)

{
  if (*(EVP_CIPHER_CTX **)(param_1 + 0x3cc) != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(param_1 + 0x3cc));
    *(undefined4 *)(param_1 + 0x3cc) = 0;
  }
  if (*(EVP_CIPHER_CTX **)(param_1 + 0x3ec) != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(param_1 + 0x3ec));
    *(undefined4 *)(param_1 + 0x3ec) = 0;
  }
  COMP_CTX_free(*(COMP_CTX **)(param_1 + 1000));
  *(undefined4 *)(param_1 + 1000) = 0;
  COMP_CTX_free(*(COMP_CTX **)(param_1 + 0x3e4));
  *(undefined4 *)(param_1 + 0x3e4) = 0;
  return;
}

