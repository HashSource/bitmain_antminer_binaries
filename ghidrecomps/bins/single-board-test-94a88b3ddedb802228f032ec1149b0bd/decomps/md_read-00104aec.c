
BIO * md_read(BIO *param_1,void *param_2,int param_3)

{
  BIO *b;
  int iVar1;
  EVP_MD_CTX *ctx;
  
  if (param_2 != (void *)0x0) {
    ctx = (EVP_MD_CTX *)param_1->ptr;
    if (ctx == (EVP_MD_CTX *)0x0) {
      b = (BIO *)0x0;
    }
    else {
      b = param_1->next_bio;
      if (b != (BIO *)0x0) {
        b = (BIO *)BIO_read(b,param_2,param_3);
        if (((param_1->init == 0) || ((int)b < 1)) ||
           (iVar1 = EVP_DigestUpdate(ctx,param_2,(size_t)b), 0 < iVar1)) {
          BIO_clear_flags(param_1,0xf);
          BIO_copy_next_retry(param_1);
        }
        else {
          b = (BIO *)0xffffffff;
        }
      }
    }
    return b;
  }
  return (BIO *)0x0;
}

