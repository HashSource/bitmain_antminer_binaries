
int HMAC_Init_ex(HMAC_CTX *ctx,void *key,int len,EVP_MD *md,ENGINE *impl)

{
  int iVar1;
  size_t sVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  EVP_MD_CTX *ctx_00;
  uint auStack_a0 [32];
  uint uStack_20;
  
  puVar5 = auStack_a0;
  if (md == (EVP_MD *)0x0) {
    md = ctx->md;
    if (md == (EVP_MD *)0x0) goto LAB_0009746e;
    if (key != (void *)0x0) goto LAB_0009745a;
LAB_00097512:
    iVar1 = EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->i_ctx);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    if (ctx->md != md) {
      uVar6 = 1 - (int)key;
      if ((void *)0x1 < key) {
        uVar6 = 0;
      }
      if ((uVar6 | (uint)len >> 0x1f) != 0) goto LAB_0009746e;
    }
    ctx->md = md;
    if (key == (void *)0x0) {
LAB_0009749c:
      puVar8 = &ctx->key_length;
      puVar3 = auStack_a0;
      puVar7 = puVar8;
      do {
        puVar7 = puVar7 + 1;
        puVar4 = puVar3 + 1;
        *puVar3 = *puVar7 ^ 0x36363636;
        puVar3 = puVar4;
      } while (puVar4 != &uStack_20);
      iVar1 = EVP_DigestInit_ex(&ctx->i_ctx,md,impl);
      if (iVar1 != 0) {
        sVar2 = EVP_MD_block_size(md);
        iVar1 = EVP_DigestUpdate(&ctx->i_ctx,auStack_a0,sVar2);
        if (iVar1 != 0) {
          do {
            puVar8 = puVar8 + 1;
            puVar7 = puVar5 + 1;
            *puVar5 = *puVar8 ^ 0x5c5c5c5c;
            puVar5 = puVar7;
          } while (puVar7 != &uStack_20);
          iVar1 = EVP_DigestInit_ex(&ctx->o_ctx,md,impl);
          if (iVar1 != 0) {
            sVar2 = EVP_MD_block_size(md);
            iVar1 = EVP_DigestUpdate(&ctx->o_ctx,auStack_a0,sVar2);
            if (iVar1 != 0) goto LAB_00097512;
          }
        }
      }
    }
    else {
LAB_0009745a:
      iVar1 = EVP_MD_block_size(md);
      if (0x80 < iVar1) {
        OpenSSLDie(DAT_00097580,0x74,DAT_00097584);
      }
      if (iVar1 < len) {
        ctx_00 = &ctx->md_ctx;
        iVar1 = EVP_DigestInit_ex(ctx_00,md,impl);
        if (((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx_00,key,len), iVar1 != 0)) &&
           (iVar1 = EVP_DigestFinal_ex(ctx_00,ctx->key,&ctx->key_length), iVar1 != 0)) {
          len = ctx->key_length;
          goto LAB_00097488;
        }
      }
      else if ((uint)len < 0x81) {
        memcpy(ctx->key,key,len);
        ctx->key_length = len;
LAB_00097488:
        if (len != 0x80) {
          memset(ctx->key + len,0,0x80 - len);
        }
        goto LAB_0009749c;
      }
    }
LAB_0009746e:
    iVar1 = 0;
  }
  return iVar1;
}

