
EVP_MD_CTX * ssl_replace_hash(undefined4 *param_1,EVP_MD *param_2)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  
  ssl_clear_hash_ctx();
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  *param_1 = ctx;
  if (ctx != (EVP_MD_CTX *)0x0) {
    if (param_2 == (EVP_MD *)0x0) {
      return ctx;
    }
    iVar1 = EVP_DigestInit_ex(ctx,param_2,(ENGINE *)0x0);
    ctx = (EVP_MD_CTX *)*param_1;
    if (0 < iVar1) {
      return ctx;
    }
  }
  EVP_MD_CTX_free(ctx);
  *param_1 = 0;
  return (EVP_MD_CTX *)0x0;
}

