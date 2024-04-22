
void ssl_clear_hash_ctx(EVP_MD_CTX **param_1)

{
  if (*param_1 != (EVP_MD_CTX *)0x0) {
    EVP_MD_CTX_destroy(*param_1);
  }
  *param_1 = (EVP_MD_CTX *)0x0;
  return;
}

