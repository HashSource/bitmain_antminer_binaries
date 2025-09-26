
int EVP_DigestVerifyFinal(EVP_MD_CTX *ctx,uchar *sig,size_t siglen)

{
  int iVar1;
  size_t local_74;
  EVP_MD_CTX EStack_70;
  uchar auStack_58 [68];
  
  if (*(int *)(*(int *)ctx->pctx + 0x48) == 0) {
    EVP_MD_CTX_init(&EStack_70);
    iVar1 = EVP_MD_CTX_copy_ex(&EStack_70,ctx);
    if (iVar1 != 0) {
      iVar1 = EVP_DigestFinal_ex(&EStack_70,auStack_58,&local_74);
      EVP_MD_CTX_cleanup(&EStack_70);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = EVP_PKEY_verify(ctx->pctx,sig,siglen,auStack_58,local_74);
      return iVar1;
    }
  }
  else {
    EVP_MD_CTX_init(&EStack_70);
    iVar1 = EVP_MD_CTX_copy_ex(&EStack_70,ctx);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*(int *)EStack_70.pctx + 0x48))(EStack_70.pctx,sig,siglen,&EStack_70);
      EVP_MD_CTX_cleanup(&EStack_70);
      return iVar1;
    }
  }
  return -1;
}

