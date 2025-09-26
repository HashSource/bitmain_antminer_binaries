
/* WARNING: Type propagation algorithm not settling */

int HMAC_Init_ex(HMAC_CTX *ctx,void *key,int len,EVP_MD *md,ENGINE *impl)

{
  int iVar1;
  size_t sVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  EVP_MD_CTX *pEVar7;
  uint local_144;
  uint auStack_140 [36];
  uint local_b0 [37];
  
  if (md == (EVP_MD *)0x0) {
    md = ctx->md;
    if (md == (EVP_MD *)0x0) {
      return 0;
    }
  }
  else {
    if ((md != ctx->md) && (key == (void *)0x0 || len < 0)) {
      return 0;
    }
    ctx->md = md;
  }
  iVar1 = EVP_MD_meth_get_flags(md);
  if (iVar1 << 0x1e < 0) {
    return 0;
  }
  if (key == (void *)0x0) {
    iVar1 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)(ctx->md_ctx).digest,(EVP_MD_CTX *)(ctx->md_ctx).engine
                              );
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  iVar1 = EVP_MD_block_size(md);
  if (0x90 < iVar1) {
    return 0;
  }
  if (iVar1 < len) {
    iVar1 = EVP_DigestInit_ex((EVP_MD_CTX *)(ctx->md_ctx).digest,md,impl);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = EVP_DigestUpdate((EVP_MD_CTX *)(ctx->md_ctx).digest,key,len);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = EVP_DigestFinal_ex((EVP_MD_CTX *)(ctx->md_ctx).digest,(uchar *)local_b0,&local_144);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    if (0x90 < (uint)len) {
      return 0;
    }
    memcpy(local_b0,key,len);
    local_144 = len;
  }
  if (local_144 != 0x90) {
    memset((void *)(local_144 + (int)local_b0),0,0x90 - local_144);
  }
  puVar6 = auStack_140 + 0x23;
  puVar3 = auStack_140;
  puVar5 = puVar6;
  do {
    puVar5 = puVar5 + 1;
    puVar4 = puVar3 + 1;
    *puVar3 = *puVar5 ^ 0x36363636;
    puVar3 = puVar4;
  } while (puVar4 != local_b0);
  iVar1 = EVP_DigestInit_ex((EVP_MD_CTX *)(ctx->md_ctx).engine,md,impl);
  if (iVar1 != 0) {
    pEVar7 = (EVP_MD_CTX *)(ctx->md_ctx).engine;
    sVar2 = EVP_MD_block_size(md);
    iVar1 = EVP_DigestUpdate(pEVar7,auStack_140,sVar2);
    puVar5 = auStack_140;
    if (iVar1 != 0) {
      do {
        puVar6 = puVar6 + 1;
        puVar3 = puVar5 + 1;
        *puVar5 = *puVar6 ^ 0x5c5c5c5c;
        puVar5 = puVar3;
      } while (puVar3 != local_b0);
      iVar1 = EVP_DigestInit_ex((EVP_MD_CTX *)(ctx->md_ctx).flags,md,impl);
      if (iVar1 != 0) {
        pEVar7 = (EVP_MD_CTX *)(ctx->md_ctx).flags;
        sVar2 = EVP_MD_block_size(md);
        iVar1 = EVP_DigestUpdate(pEVar7,auStack_140,sVar2);
        if (iVar1 != 0) {
          iVar1 = EVP_MD_CTX_copy_ex((EVP_MD_CTX *)(ctx->md_ctx).digest,
                                     (EVP_MD_CTX *)(ctx->md_ctx).engine);
          if (iVar1 != 0) {
            iVar1 = 1;
          }
          goto LAB_0013e354;
        }
      }
    }
  }
  iVar1 = 0;
LAB_0013e354:
  OPENSSL_cleanse(local_b0,0x90);
  OPENSSL_cleanse(auStack_140,0x90);
  return iVar1;
}

