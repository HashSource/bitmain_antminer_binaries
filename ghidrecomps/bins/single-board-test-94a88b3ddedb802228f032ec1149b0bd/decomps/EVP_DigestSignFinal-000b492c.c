
int EVP_DigestSignFinal(EVP_MD_CTX *ctx,uchar *sigret,size_t *siglen)

{
  size_t tbslen;
  int iVar1;
  int *piVar2;
  code *pcVar3;
  code *pcVar4;
  size_t local_74;
  EVP_MD_CTX EStack_70;
  uchar auStack_58 [64];
  
  piVar2 = (int *)ctx->pctx;
  iVar1 = *piVar2;
  if (*(int *)(iVar1 + 4) << 0x1d < 0) {
    if (sigret == (uchar *)0x0) {
      iVar1 = (**(code **)(iVar1 + 0x40))(piVar2,0,siglen,ctx);
      return iVar1;
    }
    piVar2 = (int *)EVP_PKEY_CTX_dup((EVP_PKEY_CTX *)piVar2);
    if (piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar2 + 0x40))(piVar2,sigret,siglen,ctx);
      EVP_PKEY_CTX_free((EVP_PKEY_CTX *)piVar2);
      return iVar1;
    }
  }
  else {
    pcVar4 = *(code **)(iVar1 + 0x40);
    pcVar3 = pcVar4;
    if (pcVar4 != (code *)0x0) {
      pcVar3 = (code *)0x1;
    }
    if (sigret == (uchar *)0x0) {
      if (pcVar3 != (code *)0x0) {
        iVar1 = (*pcVar4)(piVar2,0,siglen,ctx);
        return (uint)(0 < iVar1);
      }
      tbslen = EVP_MD_size(ctx->digest);
      if (-1 < (int)tbslen) {
        iVar1 = EVP_PKEY_sign((EVP_PKEY_CTX *)piVar2,(uchar *)0x0,siglen,(uchar *)0x0,tbslen);
        return (uint)(0 < iVar1);
      }
    }
    else {
      EVP_MD_CTX_init(&EStack_70);
      iVar1 = EVP_MD_CTX_copy_ex(&EStack_70,ctx);
      if (iVar1 != 0) {
        if (pcVar3 == (code *)0x0) {
          iVar1 = EVP_DigestFinal_ex(&EStack_70,auStack_58,&local_74);
        }
        else {
          iVar1 = (**(code **)(*(int *)EStack_70.pctx + 0x40))(EStack_70.pctx,sigret,siglen);
        }
        EVP_MD_CTX_cleanup(&EStack_70);
        if (iVar1 == 0) {
          pcVar3 = (code *)((uint)pcVar3 | 1);
        }
        if (pcVar3 != (code *)0x0) {
          return iVar1;
        }
        iVar1 = EVP_PKEY_sign(ctx->pctx,sigret,siglen,auStack_58,local_74);
        if (0 < iVar1) {
          return 1;
        }
      }
    }
  }
  return 0;
}

