
void ssl_clear_hash_ctx(undefined4 *param_1)

{
  EVP_MD_CTX_free(*param_1);
  *param_1 = 0;
  return;
}

