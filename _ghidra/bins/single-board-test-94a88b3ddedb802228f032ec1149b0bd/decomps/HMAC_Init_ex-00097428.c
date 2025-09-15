
int HMAC_Init_ex(HMAC_CTX *ctx,void *key,int len,EVP_MD *md,ENGINE *impl)

{
  size_t sVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  EVP_MD_CTX *ctx_00;
  uint auStack_a0 [32];
  uint uStack_20;
  
  puVar4 = auStack_a0;
  if (md == (EVP_MD *)0x0) {
    md = ctx->md;
    if (md == (EVP_MD *)0x0) goto LAB_0009746e;
    if (key != (void *)0x0) goto LAB_0009745a;
LAB_00097512:
    iVar5 = EVP_MD_CTX_copy_ex(&ctx->md_ctx,&ctx->i_ctx);
    if (iVar5 != 0) {
      iVar5 = 1;
    }
  }
  else {
    if (ctx->md != md) {
      iVar5 = 1 - (int)key;
      if ((void *)0x1 < key) {
        iVar5 = 0;
      }
      if (iVar5 != 0 || len < 0) goto LAB_0009746e;
    }
    ctx->md = md;
    if (key == (void *)0x0) {
LAB_0009749c:
      puVar7 = &ctx->key_length;
      puVar2 = auStack_a0;
      puVar6 = puVar7;
      do {
        puVar6 = puVar6 + 1;
        puVar3 = puVar2 + 1;
        *puVar2 = *puVar6 ^ 0x36363636;
        puVar2 = puVar3;
      } while (puVar3 != &uStack_20);
      iVar5 = EVP_DigestInit_ex(&ctx->i_ctx,md,impl);
      if (iVar5 != 0) {
        sVar1 = EVP_MD_block_size(md);
        iVar5 = EVP_DigestUpdate(&ctx->i_ctx,auStack_a0,sVar1);
        if (iVar5 != 0) {
          do {
            puVar7 = puVar7 + 1;
            puVar6 = puVar4 + 1;
            *puVar4 = *puVar7 ^ 0x5c5c5c5c;
            puVar4 = puVar6;
          } while (puVar6 != &uStack_20);
          iVar5 = EVP_DigestInit_ex(&ctx->o_ctx,md,impl);
          if (iVar5 != 0) {
            sVar1 = EVP_MD_block_size(md);
            iVar5 = EVP_DigestUpdate(&ctx->o_ctx,auStack_a0,sVar1);
            if (iVar5 != 0) goto LAB_00097512;
          }
        }
      }
    }
    else {
LAB_0009745a:
      iVar5 = EVP_MD_block_size(md);
      if (0x80 < iVar5) {
        OpenSSLDie("hmac.c",0x74,"j <= (int)sizeof(ctx->key)");
      }
      if (iVar5 < len) {
        ctx_00 = &ctx->md_ctx;
        iVar5 = EVP_DigestInit_ex(ctx_00,md,impl);
        if (((iVar5 != 0) && (iVar5 = EVP_DigestUpdate(ctx_00,key,len), iVar5 != 0)) &&
           (iVar5 = EVP_DigestFinal_ex(ctx_00,ctx->key,&ctx->key_length), iVar5 != 0)) {
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
    iVar5 = 0;
  }
  return iVar5;
}

