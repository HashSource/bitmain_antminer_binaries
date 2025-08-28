
void ssl3_free_digest_list(int param_1)

{
  undefined4 *ptr;
  
  ptr = *(undefined4 **)(*(int *)(param_1 + 0x58) + 0x17c);
  if (ptr != (undefined4 *)0x0) {
    if ((EVP_MD_CTX *)*ptr != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy((EVP_MD_CTX *)*ptr);
      ptr = *(undefined4 **)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if ((EVP_MD_CTX *)ptr[1] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy((EVP_MD_CTX *)ptr[1]);
      ptr = *(undefined4 **)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if ((EVP_MD_CTX *)ptr[2] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy((EVP_MD_CTX *)ptr[2]);
      ptr = *(undefined4 **)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if ((EVP_MD_CTX *)ptr[3] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy((EVP_MD_CTX *)ptr[3]);
      ptr = *(undefined4 **)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if ((EVP_MD_CTX *)ptr[4] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy((EVP_MD_CTX *)ptr[4]);
      ptr = *(undefined4 **)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    if ((EVP_MD_CTX *)ptr[5] != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy((EVP_MD_CTX *)ptr[5]);
      ptr = *(undefined4 **)(*(int *)(param_1 + 0x58) + 0x17c);
    }
    CRYPTO_free(ptr);
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x17c) = 0;
  }
  return;
}

