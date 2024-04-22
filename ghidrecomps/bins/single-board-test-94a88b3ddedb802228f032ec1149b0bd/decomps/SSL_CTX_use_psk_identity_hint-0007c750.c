
int SSL_CTX_use_psk_identity_hint(SSL_CTX *ctx,char *identity_hint)

{
  size_t sVar1;
  char *pcVar2;
  
  if ((identity_hint == (char *)0x0) || (sVar1 = strlen(identity_hint), sVar1 < 0x81)) {
    if (ctx->psk_identity_hint != (char *)0x0) {
      CRYPTO_free(ctx->psk_identity_hint);
    }
    if (identity_hint == (char *)0x0) {
      pcVar2 = (char *)0x1;
      ctx->psk_identity_hint = (char *)0x0;
    }
    else {
      pcVar2 = BUF_strdup(identity_hint);
      ctx->psk_identity_hint = pcVar2;
      if (pcVar2 != (char *)0x0) {
        pcVar2 = (char *)0x1;
      }
    }
  }
  else {
    ERR_put_error(0x14,0x110,0x92,DAT_0007c7a4,0xd39);
    pcVar2 = (char *)0x0;
  }
  return (int)pcVar2;
}

