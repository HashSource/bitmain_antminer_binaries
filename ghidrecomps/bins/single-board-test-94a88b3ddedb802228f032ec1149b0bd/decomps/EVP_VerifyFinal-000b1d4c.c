
int EVP_VerifyFinal(EVP_MD_CTX *ctx,uchar *sigbuf,uint siglen,EVP_PKEY *pkey)

{
  int iVar1;
  EVP_MD *pEVar2;
  EVP_PKEY_CTX *ctx_00;
  uint local_74;
  EVP_MD_CTX EStack_70;
  uchar auStack_58 [68];
  
  EVP_MD_CTX_init(&EStack_70);
  iVar1 = EVP_MD_CTX_copy_ex(&EStack_70,ctx);
  if ((iVar1 == 0) || (iVar1 = EVP_DigestFinal_ex(&EStack_70,auStack_58,&local_74), iVar1 == 0)) {
    ctx_00 = (EVP_PKEY_CTX *)0x0;
    iVar1 = 0;
  }
  else {
    EVP_MD_CTX_cleanup(&EStack_70);
    pEVar2 = ctx->digest;
    if (-1 < (int)(pEVar2->flags << 0x1d)) {
      if ((pEVar2->required_pkey_type[0] != 0) &&
         ((iVar1 = pkey->type, iVar1 == pEVar2->required_pkey_type[0] ||
          ((pEVar2->required_pkey_type[1] != 0 &&
           ((iVar1 == pEVar2->required_pkey_type[1] ||
            ((pEVar2->required_pkey_type[2] != 0 &&
             ((iVar1 == pEVar2->required_pkey_type[2] ||
              ((pEVar2->required_pkey_type[3] != 0 && (pEVar2->required_pkey_type[3] == iVar1)))))))
            ))))))) {
        if (pEVar2->verify != (_func_1226 *)0x0) {
          iVar1 = (*pEVar2->verify)(pEVar2->type,auStack_58,local_74,sigbuf,siglen,(pkey->pkey).ptr)
          ;
          return iVar1;
        }
        ERR_put_error(6,0x6c,0x69,DAT_000b1e3c,0x6e);
        return 0;
      }
      ERR_put_error(6,0x6c,0x6e,DAT_000b1e3c,0x6a);
      return -1;
    }
    ctx_00 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if (((ctx_00 == (EVP_PKEY_CTX *)0x0) || (iVar1 = EVP_PKEY_verify_init(ctx_00), iVar1 < 1)) ||
       (iVar1 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,ctx->digest), iVar1 < 1)) {
      iVar1 = -1;
    }
    else {
      iVar1 = EVP_PKEY_verify(ctx_00,sigbuf,siglen,auStack_58,local_74);
    }
  }
  EVP_PKEY_CTX_free(ctx_00);
  return iVar1;
}

