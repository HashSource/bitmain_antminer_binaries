
ulong X509_NAME_hash_old(X509_NAME *x)

{
  EVP_MD_CTX *ctx;
  EVP_MD *type;
  int iVar1;
  ulong local_20 [5];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx == (EVP_MD_CTX *)0x0) {
    return 0;
  }
  i2d_X509_NAME(x,(uchar **)0x0);
  EVP_MD_CTX_set_flags(ctx,8);
  type = EVP_md5();
  iVar1 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
  if (((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(ctx,x->bytes->data,x->bytes->length), iVar1 == 0))
     || (iVar1 = EVP_DigestFinal_ex(ctx,(uchar *)local_20,(uint *)0x0), iVar1 == 0)) {
    local_20[0] = 0;
  }
  EVP_MD_CTX_free(ctx);
  return local_20[0];
}

