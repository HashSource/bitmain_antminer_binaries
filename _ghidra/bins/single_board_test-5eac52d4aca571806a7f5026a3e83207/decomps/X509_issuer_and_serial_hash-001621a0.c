
ulong X509_issuer_and_serial_hash(X509 *a)

{
  EVP_MD_CTX *ctx;
  char *__s;
  EVP_MD *type;
  ulong uVar1;
  size_t cnt;
  ulong local_20 [4];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if ((ctx == (EVP_MD_CTX *)0x0) ||
     (__s = X509_NAME_oneline((X509_NAME *)(a->ex_data).dummy,(char *)0x0,0), __s == (char *)0x0)) {
    __s = (char *)0x0;
    local_20[0] = 0;
  }
  else {
    type = EVP_md5();
    uVar1 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
    if (uVar1 != 0) {
      cnt = strlen(__s);
      uVar1 = EVP_DigestUpdate(ctx,__s,cnt);
      if (((uVar1 != 0) &&
          (uVar1 = EVP_DigestUpdate(ctx,(void *)a->valid,(size_t)a->sig_alg), uVar1 != 0)) &&
         (uVar1 = EVP_DigestFinal_ex(ctx,(uchar *)local_20,(uint *)0x0), uVar1 != 0))
      goto LAB_001621d0;
    }
    local_20[0] = uVar1;
  }
LAB_001621d0:
  CRYPTO_free(__s);
  EVP_MD_CTX_free(ctx);
  return local_20[0];
}

