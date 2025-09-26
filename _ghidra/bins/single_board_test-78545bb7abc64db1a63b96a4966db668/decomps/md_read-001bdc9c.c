
size_t md_read(BIO *param_1,void *param_2,int param_3)

{
  EVP_MD_CTX *ctx;
  BIO *b;
  size_t cnt;
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  ctx = (EVP_MD_CTX *)BIO_get_data();
  b = BIO_next(param_1);
  if (b == (BIO *)0x0 || ctx == (EVP_MD_CTX *)0x0) {
    return 0;
  }
  cnt = BIO_read(b,param_2,param_3);
  sVar1 = BIO_get_init(param_1);
  sVar2 = sVar1;
  if (sVar1 != 0) {
    sVar2 = cnt;
  }
  if (((sVar1 != 0 && cnt != 0) && -1 < (int)sVar2) &&
     (iVar3 = EVP_DigestUpdate(ctx,param_2,cnt), iVar3 < 1)) {
    return 0xffffffff;
  }
  BIO_clear_flags(param_1,0xf);
  BIO_copy_next_retry(param_1);
  return cnt;
}

