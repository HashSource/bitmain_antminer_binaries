
int EVP_DigestSignFinal(EVP_MD_CTX *ctx,uchar *sigret,size_t *siglen)

{
  bool bVar1;
  EVP_MD_CTX *out;
  size_t tbslen;
  int iVar2;
  EVP_PKEY_CTX *pEVar3;
  code *pcVar4;
  uint local_64;
  uchar auStack_60 [64];
  
  pEVar3 = ctx->pctx;
  iVar2 = *(int *)pEVar3;
  local_64 = *(uint *)(iVar2 + 4) & 4;
  if (local_64 != 0) {
    if ((sigret != (uchar *)0x0) && (-1 < (int)(ctx->flags << 0x16))) {
      pEVar3 = EVP_PKEY_CTX_dup(pEVar3);
      if (pEVar3 != (EVP_PKEY_CTX *)0x0) {
        iVar2 = (**(code **)(*(int *)pEVar3 + 0x40))(pEVar3,sigret,siglen,ctx);
        EVP_PKEY_CTX_free(pEVar3);
        return iVar2;
      }
      return 0;
    }
    iVar2 = (**(code **)(iVar2 + 0x40))(pEVar3,sigret,siglen,ctx);
    return iVar2;
  }
  pcVar4 = *(code **)(iVar2 + 0x40);
  if (pcVar4 == (code *)0x0) {
    if (sigret == (uchar *)0x0) {
      tbslen = EVP_MD_size(ctx->digest);
      if (-1 < (int)tbslen) {
        iVar2 = EVP_PKEY_sign(pEVar3,(uchar *)0x0,siglen,(uchar *)0x0,tbslen);
        return (uint)(0 < iVar2);
      }
      return 0;
    }
    if ((int)(ctx->flags << 0x16) < 0) {
      iVar2 = EVP_DigestFinal_ex(ctx,auStack_60,&local_64);
      bVar1 = iVar2 == 0;
      goto LAB_0013150c;
    }
    bVar1 = false;
  }
  else {
    if (sigret == (uchar *)0x0) {
      iVar2 = (*pcVar4)(pEVar3,0,siglen,ctx);
      return (uint)(0 < iVar2);
    }
    if ((int)(ctx->flags << 0x16) < 0) {
      iVar2 = (*pcVar4)(pEVar3,sigret,siglen,ctx);
      return iVar2;
    }
    bVar1 = true;
  }
  out = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (out == (EVP_MD_CTX *)0x0) {
    return 0;
  }
  iVar2 = EVP_MD_CTX_copy_ex(out,ctx);
  if (iVar2 == 0) {
    EVP_MD_CTX_free(out);
    return 0;
  }
  if (bVar1) {
    iVar2 = (**(code **)(*(int *)out->pctx + 0x40))(out->pctx,sigret,siglen,out);
  }
  else {
    iVar2 = EVP_DigestFinal_ex(out,auStack_60,&local_64);
  }
  EVP_MD_CTX_free(out);
  if (iVar2 == 0) {
    bVar1 = true;
  }
LAB_0013150c:
  if (bVar1) {
    return iVar2;
  }
  iVar2 = EVP_PKEY_sign(ctx->pctx,sigret,siglen,auStack_60,local_64);
  return (uint)(0 < iVar2);
}

