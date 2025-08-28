
int EVP_DigestSignFinal(EVP_MD_CTX *ctx,uchar *sigret,size_t *siglen)

{
  size_t tbslen;
  int iVar1;
  EVP_PKEY_CTX *pEVar2;
  code *pcVar3;
  code *pcVar4;
  size_t local_74;
  EVP_MD_CTX EStack_70;
  uchar auStack_58 [64];
  
  pEVar2 = ctx->pctx;
  iVar1 = *(int *)pEVar2;
  if (*(int *)(iVar1 + 4) << 0x1d < 0) {
    if (sigret == (uchar *)0x0) {
      iVar1 = (**(code **)(iVar1 + 0x40))(pEVar2,0,siglen,ctx);
      return iVar1;
    }
    pEVar2 = EVP_PKEY_CTX_dup(pEVar2);
    if (pEVar2 != (EVP_PKEY_CTX *)0x0) {
      iVar1 = (**(code **)(*(int *)pEVar2 + 0x40))(pEVar2,sigret,siglen,ctx);
      EVP_PKEY_CTX_free(pEVar2);
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
        iVar1 = (*pcVar4)(pEVar2,0,siglen,ctx);
        return (uint)(0 < iVar1);
      }
      tbslen = EVP_MD_size(ctx->digest);
      if (-1 < (int)tbslen) {
        iVar1 = EVP_PKEY_sign(pEVar2,(uchar *)0x0,siglen,(uchar *)0x0,tbslen);
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
          iVar1 = (**(code **)(*(int *)EStack_70.pctx + 0x40))
                            (EStack_70.pctx,sigret,siglen,&EStack_70);
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

