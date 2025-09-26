
int SSL_CTX_use_psk_identity_hint(SSL_CTX *ctx,char *identity_hint)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  if (identity_hint == (char *)0x0) {
    CRYPTO_free(*(void **)(ctx->verify_mode + 0x104));
    *(undefined4 *)(ctx->verify_mode + 0x104) = 0;
    return 1;
  }
  sVar1 = strlen(identity_hint);
  if (sVar1 < 0x81) {
    CRYPTO_free(*(void **)(ctx->verify_mode + 0x104));
    iVar4 = ctx->verify_mode;
    pcVar2 = CRYPTO_strdup(identity_hint,"ssl/ssl_lib.c",0x10f6);
    iVar3 = ctx->verify_mode;
    *(char **)(iVar4 + 0x104) = pcVar2;
    iVar3 = *(int *)(iVar3 + 0x104);
    if (iVar3 != 0) {
      iVar3 = 1;
    }
    return iVar3;
  }
  ERR_put_error(0x14,0x110,0x92,"ssl/ssl_lib.c",0x10f1);
  return 0;
}

