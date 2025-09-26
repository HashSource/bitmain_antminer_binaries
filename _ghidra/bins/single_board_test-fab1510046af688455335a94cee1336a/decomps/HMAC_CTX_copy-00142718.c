
int HMAC_CTX_copy(HMAC_CTX *dctx,HMAC_CTX *sctx)

{
  int iVar1;
  EVP_MD *pEVar2;
  
  iVar1 = EVP_MD_CTX_copy(&dctx->i_ctx,&sctx->i_ctx);
  if (((iVar1 != 0) && (iVar1 = EVP_MD_CTX_copy(&dctx->o_ctx,&sctx->o_ctx), iVar1 != 0)) &&
     (iVar1 = EVP_MD_CTX_copy(&dctx->md_ctx,&sctx->md_ctx), iVar1 != 0)) {
    memcpy(dctx->key,sctx->key,0x80);
    pEVar2 = sctx->md;
    dctx->key_length = sctx->key_length;
    dctx->md = pEVar2;
    return 1;
  }
  return 0;
}

