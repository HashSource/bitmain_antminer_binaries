
int EVP_DigestVerifyFinal(EVP_MD_CTX *ctx,uchar *sig,size_t siglen)

{
  EVP_MD_CTX *out;
  int iVar1;
  code *pcVar2;
  uint uVar3;
  uint local_64;
  uchar auStack_60 [68];
  
  local_64 = 0;
  pcVar2 = *(code **)(*(int *)ctx->pctx + 0x48);
  if (pcVar2 == (code *)0x0) {
    uVar3 = ctx->flags & 0x200;
    if (uVar3 != 0) {
      iVar1 = EVP_DigestFinal_ex(ctx,auStack_60,&local_64);
      uVar3 = 0;
      goto LAB_0013b238;
    }
  }
  else {
    if ((int)(ctx->flags << 0x16) < 0) {
      iVar1 = (*pcVar2)(ctx->pctx,sig,siglen,ctx);
      return iVar1;
    }
    uVar3 = 1;
  }
  out = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (out == (EVP_MD_CTX *)0x0) {
    return -1;
  }
  iVar1 = EVP_MD_CTX_copy_ex(out,ctx);
  if (iVar1 == 0) {
    EVP_MD_CTX_free(out);
    return -1;
  }
  if (uVar3 == 0) {
    iVar1 = EVP_DigestFinal_ex(out,auStack_60,&local_64);
  }
  else {
    iVar1 = (**(code **)(*(int *)out->pctx + 0x48))(out->pctx,sig,siglen,out);
  }
  EVP_MD_CTX_free(out);
LAB_0013b238:
  if (iVar1 == 0) {
    uVar3 = uVar3 | 1;
  }
  if (uVar3 != 0) {
    return iVar1;
  }
  iVar1 = EVP_PKEY_verify(ctx->pctx,sig,siglen,auStack_60,local_64);
  return iVar1;
}

