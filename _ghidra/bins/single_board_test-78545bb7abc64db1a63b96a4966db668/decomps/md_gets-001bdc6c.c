
uint md_gets(undefined4 param_1,uchar *param_2,int param_3)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  uint local_14 [2];
  
  ctx = (EVP_MD_CTX *)BIO_get_data();
  if (param_3 < ctx->digest->md_size) {
    local_14[0] = 0;
  }
  else {
    iVar1 = EVP_DigestFinal_ex(ctx,param_2,local_14);
    if (iVar1 < 1) {
      local_14[0] = 0xffffffff;
    }
  }
  return local_14[0];
}

