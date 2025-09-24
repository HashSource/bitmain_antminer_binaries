
int HMAC_CTX_copy(HMAC_CTX *dctx,HMAC_CTX *sctx)

{
  int iVar1;
  ENGINE *pEVar2;
  ulong uVar3;
  EVP_MD *pEVar4;
  
  if ((dctx->md_ctx).engine == (ENGINE *)0x0) {
    pEVar2 = (ENGINE *)EVP_MD_CTX_new();
    (dctx->md_ctx).engine = pEVar2;
    if (pEVar2 == (ENGINE *)0x0) goto LAB_001349da;
  }
  if ((dctx->md_ctx).flags == 0) {
    uVar3 = EVP_MD_CTX_new();
    (dctx->md_ctx).flags = uVar3;
    if (uVar3 != 0) goto LAB_001349c8;
  }
  else {
LAB_001349c8:
    if ((dctx->md_ctx).digest == (EVP_MD *)0x0) {
      pEVar4 = (EVP_MD *)EVP_MD_CTX_new();
      (dctx->md_ctx).digest = pEVar4;
      if (pEVar4 == (EVP_MD *)0x0) goto LAB_001349d8;
    }
    iVar1 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)(dctx->md_ctx).engine,
                               (EVP_MD_CTX *)(sctx->md_ctx).engine);
    if (((iVar1 != 0) &&
        (iVar1 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)(dctx->md_ctx).flags,
                                    (EVP_MD_CTX *)(sctx->md_ctx).flags), iVar1 != 0)) &&
       (iVar1 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)(dctx->md_ctx).digest,
                                   (EVP_MD_CTX *)(sctx->md_ctx).digest), iVar1 != 0)) {
      dctx->md = sctx->md;
      return 1;
    }
  }
LAB_001349d8:
  pEVar2 = (dctx->md_ctx).engine;
LAB_001349da:
  EVP_MD_CTX_reset(pEVar2);
  EVP_MD_CTX_reset((dctx->md_ctx).flags);
  EVP_MD_CTX_reset((dctx->md_ctx).digest);
  dctx->md = (EVP_MD *)0x0;
  return 0;
}

