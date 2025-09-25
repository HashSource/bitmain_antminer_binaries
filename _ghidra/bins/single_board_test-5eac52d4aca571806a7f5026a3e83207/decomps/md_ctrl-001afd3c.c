
long md_ctrl(BIO *param_1,int param_2,long param_3,EVP_MD *param_4)

{
  EVP_MD_CTX *ctx;
  BIO *bp;
  long lVar1;
  int iVar2;
  EVP_MD_CTX *out;
  
  ctx = (EVP_MD_CTX *)BIO_get_data();
  bp = BIO_next(param_1);
  if (param_2 == 0x6f) {
    iVar2 = EVP_DigestInit_ex(ctx,param_4,(ENGINE *)0x0);
    if (iVar2 < 1) {
      return iVar2;
    }
    BIO_set_init(param_1,1);
    return iVar2;
  }
  if (param_2 < 0x70) {
    if (param_2 != 0xc) {
      if (param_2 == 0x65) {
        BIO_clear_flags(param_1,0xf);
        lVar1 = BIO_ctrl(bp,0x65,param_3,param_4);
        BIO_copy_next_retry(param_1);
        return lVar1;
      }
      if (param_2 == 1) {
        iVar2 = BIO_get_init(param_1);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = EVP_DigestInit_ex(ctx,ctx->digest,(ENGINE *)0x0);
        if (iVar2 < 1) {
          return iVar2;
        }
      }
LAB_001afd68:
      lVar1 = BIO_ctrl(bp,param_2,param_3,param_4);
      return lVar1;
    }
    out = (EVP_MD_CTX *)BIO_get_data(param_4);
    iVar2 = EVP_MD_CTX_copy_ex(out,ctx);
    if (iVar2 != 0) {
      BIO_set_init(param_1,1);
      return 1;
    }
  }
  else {
    if (param_2 == 0x78) {
      param_4->type = (int)ctx;
      BIO_set_init(param_1,1);
      return 1;
    }
    if (param_2 == 0x94) {
      iVar2 = BIO_get_init(param_1);
      if (iVar2 != 0) {
        BIO_set_data(param_1,param_4);
        return 1;
      }
    }
    else {
      if (param_2 != 0x70) goto LAB_001afd68;
      iVar2 = BIO_get_init(param_1);
      if (iVar2 != 0) {
        param_4->type = (int)ctx->digest;
        return 1;
      }
    }
  }
  return 0;
}

