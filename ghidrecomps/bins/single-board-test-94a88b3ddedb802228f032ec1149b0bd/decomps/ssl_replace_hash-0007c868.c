
EVP_MD_CTX * ssl_replace_hash(EVP_MD_CTX **param_1,EVP_MD *param_2)

{
  EVP_MD_CTX *ctx;
  
  if (*param_1 != (EVP_MD_CTX *)0x0) {
    EVP_MD_CTX_destroy(*param_1);
  }
  *param_1 = (EVP_MD_CTX *)0x0;
  ctx = EVP_MD_CTX_create();
  *param_1 = ctx;
  if (param_2 != (EVP_MD *)0x0) {
    EVP_DigestInit_ex(ctx,param_2,(ENGINE *)0x0);
    ctx = *param_1;
  }
  return ctx;
}

