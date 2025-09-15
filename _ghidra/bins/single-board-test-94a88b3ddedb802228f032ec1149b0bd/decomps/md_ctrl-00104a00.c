
long md_ctrl(BIO *param_1,int param_2,long param_3,EVP_MD *param_4)

{
  long lVar1;
  EVP_MD_CTX *ctx;
  int iVar2;
  
  ctx = (EVP_MD_CTX *)param_1->ptr;
  if (param_2 == 0x6f) {
    iVar2 = EVP_DigestInit_ex(ctx,param_4,(ENGINE *)0x0);
    if (0 < iVar2) {
      param_1->init = 1;
    }
  }
  else {
    if (param_2 < 0x70) {
      if (param_2 == 0xc) {
        iVar2 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)param_4->cleanup,ctx);
        if (iVar2 != 0) {
          param_1->init = 1;
          return 1;
        }
      }
      else {
        if (param_2 == 0x65) {
          BIO_clear_flags(param_1,0xf);
          lVar1 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
          BIO_copy_next_retry(param_1);
          return lVar1;
        }
        if (param_2 != 1) {
LAB_00104a1e:
          lVar1 = BIO_ctrl(param_1->next_bio,param_2,param_3,param_4);
          return lVar1;
        }
        if (param_1->init != 0) {
          iVar2 = EVP_DigestInit_ex(ctx,ctx->digest,(ENGINE *)0x0);
          if (iVar2 < 1) {
            return iVar2;
          }
          goto LAB_00104a1e;
        }
      }
    }
    else {
      if (param_2 == 0x78) {
        param_4->type = (int)ctx;
        param_1->init = 1;
        return 1;
      }
      if (param_2 == 0x94) {
        if (param_1->init != 0) {
          param_1->ptr = param_4;
          return 1;
        }
      }
      else {
        if (param_2 != 0x70) goto LAB_00104a1e;
        if (param_1->init != 0) {
          param_4->type = (int)ctx->digest;
          return 1;
        }
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}

