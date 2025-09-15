
void ssl_clear_hash_ctx(undefined4 *param_1)

{
  if ((EVP_MD_CTX *)*param_1 != (EVP_MD_CTX *)0x0) {
    EVP_MD_CTX_destroy((EVP_MD_CTX *)*param_1);
  }
  *param_1 = 0;
  return;
}

