
int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,ENGINE *impl,uchar *key,uchar *iv,
                     int enc)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  int iVar4;
  EVP_CIPHER *pEVar5;
  ulong uVar6;
  
  if (enc == -1) {
    enc = ctx->encrypt;
  }
  else {
    if (enc != 0) {
      enc = 1;
    }
    ctx->encrypt = enc;
  }
  pEVar5 = ctx->cipher;
  if (ctx->engine == (ENGINE *)0x0) {
    if (cipher != (EVP_CIPHER *)0x0) {
      if (pEVar5 != (EVP_CIPHER *)0x0) goto LAB_000aeb5c;
      goto LAB_000aeb94;
    }
    if (pEVar5 == (EVP_CIPHER *)0x0) goto LAB_000aed38;
LAB_000aebde:
    iVar1 = pEVar5->block_size;
    if ((iVar1 != 8 && iVar1 != 1) && (iVar1 != 0x10)) {
      OpenSSLDie(DAT_000aedb8,0xd6,DAT_000aedbc);
    }
    if (((ctx->flags & 1) == 0) && (uVar6 = EVP_CIPHER_CTX_flags(ctx), (uVar6 & 0xf0007) == 0x10002)
       ) {
      ERR_put_error(6,0x7b,0xaa,DAT_000aedb8,0xda);
      return 0;
    }
    uVar6 = EVP_CIPHER_CTX_flags(ctx);
    if (-1 < (int)(uVar6 << 0x1b)) {
      uVar6 = EVP_CIPHER_CTX_flags(ctx);
      switch(uVar6 & 0xf0007) {
      case 0:
      case 1:
        break;
      case 3:
      case 4:
        ctx->num = 0;
      case 2:
        iVar1 = EVP_CIPHER_CTX_iv_length(ctx);
        if (0x10 < iVar1) {
          OpenSSLDie(DAT_000aedb8,0xee,DAT_000aedc0);
        }
        if (iv != (uchar *)0x0) {
          sVar3 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->oiv,iv,sVar3);
        }
        sVar3 = EVP_CIPHER_CTX_iv_length(ctx);
        memcpy(ctx->iv,ctx->oiv,sVar3);
        break;
      case 5:
        ctx->num = 0;
        if (iv != (uchar *)0x0) {
          sVar3 = EVP_CIPHER_CTX_iv_length(ctx);
          memcpy(ctx->iv,iv,sVar3);
        }
        break;
      default:
        goto switchD_000aec74_caseD_6;
      }
    }
    pEVar5 = ctx->cipher;
    if ((key != (uchar *)0x0) || ((int)(pEVar5->flags << 0x1a) < 0)) {
      iVar1 = (*pEVar5->init)(ctx,key,iv,enc);
      if (iVar1 == 0) {
        return 0;
      }
      pEVar5 = ctx->cipher;
    }
    iVar4 = pEVar5->block_size;
    iVar1 = 1;
    ctx->buf_len = 0;
    ctx->final_used = 0;
    ctx->block_mask = iVar4 + -1;
  }
  else {
    if (pEVar5 == (EVP_CIPHER *)0x0) {
      if (cipher == (EVP_CIPHER *)0x0) {
LAB_000aed38:
        ERR_put_error(6,0x7b,0x83,DAT_000aedb8,0xc9);
        return 0;
      }
    }
    else {
      if ((cipher == (EVP_CIPHER *)0x0) || (cipher->nid == pEVar5->nid)) goto LAB_000aebde;
LAB_000aeb5c:
      uVar6 = ctx->flags;
      if ((pEVar5->cleanup == (_func_1233 *)0x0) || (iVar1 = (*pEVar5->cleanup)(ctx), iVar1 != 0)) {
        if (ctx->cipher_data != (void *)0x0) {
          OPENSSL_cleanse(ctx->cipher_data,ctx->cipher->ctx_size);
          if (ctx->cipher_data != (void *)0x0) {
            CRYPTO_free(ctx->cipher_data);
          }
        }
        if (ctx->engine != (ENGINE *)0x0) {
          ENGINE_finish(ctx->engine);
        }
        memset(ctx,0,0x8c);
      }
      ctx->encrypt = enc;
      ctx->flags = uVar6;
    }
LAB_000aeb94:
    if (impl == (ENGINE *)0x0) {
      impl = ENGINE_get_cipher_engine(cipher->nid);
      if (impl != (ENGINE *)0x0) goto LAB_000aebaa;
LAB_000aebbc:
      iVar1 = cipher->ctx_size;
      ctx->engine = impl;
      ctx->cipher = cipher;
      if (iVar1 == 0) {
        ctx->cipher_data = (void *)0x0;
        pEVar5 = cipher;
      }
      else {
        pvVar2 = CRYPTO_malloc(iVar1,DAT_000aedb8,0xb7);
        ctx->cipher_data = pvVar2;
        if (pvVar2 == (void *)0x0) {
          ERR_put_error(6,0x7b,0x41,DAT_000aedb8,0xb9);
          return 0;
        }
        pEVar5 = ctx->cipher;
      }
      uVar6 = pEVar5->flags;
      ctx->key_len = cipher->key_len;
      ctx->flags = ctx->flags & 1;
      if (-1 < (int)(uVar6 << 0x19)) goto LAB_000aebde;
      if (pEVar5->ctrl == (_func_1236 *)0x0) {
        ERR_put_error(6,0x7c,0x84,DAT_000aedb8,0x267);
      }
      else {
        iVar1 = (*pEVar5->ctrl)(ctx,0,0,(void *)0x0);
        if (iVar1 == -1) {
          ERR_put_error(6,0x7c,0x85,DAT_000aedb8,0x26e);
        }
        else if (iVar1 != 0) {
          pEVar5 = ctx->cipher;
          goto LAB_000aebde;
        }
      }
      iVar4 = 0xc4;
    }
    else {
      iVar1 = ENGINE_init(impl);
      iVar4 = 0x8e;
      if (iVar1 != 0) {
LAB_000aebaa:
        cipher = ENGINE_get_cipher(impl,cipher->nid);
        iVar4 = 0x9d;
        if (cipher != (EVP_CIPHER *)0x0) goto LAB_000aebbc;
      }
    }
    ERR_put_error(6,0x7b,0x86,DAT_000aedb8,iVar4);
switchD_000aec74_caseD_6:
    iVar1 = 0;
  }
  return iVar1;
}

