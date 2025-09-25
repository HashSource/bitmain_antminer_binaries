
int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,ENGINE *impl,uchar *key,uchar *iv,
                     int enc)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  EVP_CIPHER *pEVar4;
  ulong uVar5;
  
  if (enc == -1) {
    enc = ctx->encrypt;
  }
  else {
    if (enc != 0) {
      enc = 1;
    }
    ctx->encrypt = enc;
  }
  if (ctx->engine == (ENGINE *)0x0) {
    pEVar4 = ctx->cipher;
    if (cipher == (EVP_CIPHER *)0x0) {
      if (pEVar4 == (EVP_CIPHER *)0x0) goto LAB_0012c216;
      goto LAB_0012c0aa;
    }
    if ((pEVar4 != (EVP_CIPHER *)0x0) || (ctx->cipher_data != (void *)0x0)) goto LAB_0012c054;
  }
  else {
    pEVar4 = ctx->cipher;
    if (pEVar4 == (EVP_CIPHER *)0x0) {
      if (cipher == (EVP_CIPHER *)0x0) {
LAB_0012c216:
        ERR_put_error(6,0x7b,0x83,"crypto/evp/evp_enc.c",0x95);
        return 0;
      }
    }
    else if ((cipher == (EVP_CIPHER *)0x0) || (cipher->nid == pEVar4->nid)) goto LAB_0012c0aa;
LAB_0012c054:
    uVar5 = ctx->flags;
    EVP_CIPHER_CTX_reset(ctx);
    ctx->encrypt = enc;
    ctx->flags = uVar5;
  }
  if (impl == (ENGINE *)0x0) {
    impl = ENGINE_get_cipher_engine(cipher->nid);
    if (impl != (ENGINE *)0x0) goto LAB_0012c076;
  }
  else {
    iVar1 = ENGINE_init(impl);
    if (iVar1 == 0) {
      iVar1 = 0x66;
      goto LAB_0012c194;
    }
LAB_0012c076:
    cipher = ENGINE_get_cipher(impl,cipher->nid);
    if (cipher == (EVP_CIPHER *)0x0) {
      ENGINE_finish(impl);
      iVar1 = 0x71;
LAB_0012c194:
      ERR_put_error(6,0x7b,0x86,"crypto/evp/evp_enc.c",iVar1);
      return 0;
    }
  }
  iVar1 = cipher->ctx_size;
  ctx->engine = impl;
  ctx->cipher = cipher;
  if (iVar1 == 0) {
    ctx->cipher_data = (void *)0x0;
    pEVar4 = cipher;
  }
  else {
    pvVar2 = (void *)CRYPTO_zalloc(iVar1,"crypto/evp/evp_enc.c",0x81);
    ctx->cipher_data = pvVar2;
    if (pvVar2 == (void *)0x0) {
      ctx->cipher = (EVP_CIPHER *)0x0;
      ERR_put_error(6,0x7b,0x41,"crypto/evp/evp_enc.c",0x84);
      return 0;
    }
    pEVar4 = ctx->cipher;
  }
  uVar5 = pEVar4->flags;
  ctx->key_len = cipher->key_len;
  ctx->flags = ctx->flags & 1;
  if ((int)(uVar5 << 0x19) < 0) {
    iVar1 = EVP_CIPHER_CTX_ctrl(ctx,0,0,(void *)0x0);
    if (iVar1 == 0) {
      ctx->cipher = (EVP_CIPHER *)0x0;
      ERR_put_error(6,0x7b,0x86,"crypto/evp/evp_enc.c",0x90);
      return 0;
    }
    pEVar4 = ctx->cipher;
  }
LAB_0012c0aa:
  if (pEVar4->block_size != 1 && (pEVar4->block_size - 8U & 0xfffffff7) != 0) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: ctx->cipher->block_size == 1 || ctx->cipher->block_size == 8 || ctx->cipher->block_size == 16"
                ,"crypto/evp/evp_enc.c",0x9e);
  }
  if ((ctx->flags & 1) == 0) {
    pEVar4 = EVP_CIPHER_CTX_cipher(ctx);
    uVar5 = EVP_CIPHER_flags(pEVar4);
    if ((uVar5 & 0xf0007) == 0x10002) {
      ERR_put_error(6,0x7b,0xaa,"crypto/evp/evp_enc.c",0xa2);
      return 0;
    }
  }
  pEVar4 = EVP_CIPHER_CTX_cipher(ctx);
  uVar5 = EVP_CIPHER_flags(pEVar4);
  if (-1 < (int)(uVar5 << 0x1b)) {
    pEVar4 = EVP_CIPHER_CTX_cipher(ctx);
    uVar5 = EVP_CIPHER_flags(pEVar4);
    switch(uVar5 & 0xf0007) {
    case 0:
    case 1:
      break;
    case 3:
    case 4:
      ctx->num = 0;
    case 2:
      iVar1 = EVP_CIPHER_CTX_iv_length(ctx);
      if (0x10 < iVar1) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: EVP_CIPHER_CTX_iv_length(ctx) <= (int)sizeof(ctx->iv)",
                    "crypto/evp/evp_enc.c",0xb6);
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
      return 0;
    }
  }
  pEVar4 = ctx->cipher;
  if ((key != (uchar *)0x0) || ((int)(pEVar4->flags << 0x1a) < 0)) {
    iVar1 = (*pEVar4->init)(ctx,key,iv,enc);
    if (iVar1 == 0) {
      return 0;
    }
    pEVar4 = ctx->cipher;
  }
  iVar1 = pEVar4->block_size;
  ctx->buf_len = 0;
  ctx->final_used = 0;
  ctx->block_mask = iVar1 + -1;
  return 1;
}

