
void ssl3_free_digest_list(int param_1)

{
  EVP_MD_CTX **ptr;
  
  ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
  if (ptr != (EVP_MD_CTX **)0x0) {
    if (*ptr != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(*ptr);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[1] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[1]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[2] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[2]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[3] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[3]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[4] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[4]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if (ptr[5] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ptr[5]);
      ptr = *(EVP_MD_CTX ***)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    CRYPTO_free(ptr);
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x17c) = 0;
  }
  return;
}

