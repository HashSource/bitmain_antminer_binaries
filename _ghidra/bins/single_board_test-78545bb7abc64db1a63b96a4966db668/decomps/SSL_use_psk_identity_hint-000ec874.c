
int SSL_use_psk_identity_hint(SSL *s,char *identity_hint)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  if (s == (SSL *)0x0) {
    return 0;
  }
  if (identity_hint != (char *)0x0) {
    sVar1 = strlen(identity_hint);
    if (sVar1 < 0x81) {
      CRYPTO_free(*(void **)(s[2].error + 0x104));
      iVar4 = s[2].error;
      pcVar2 = CRYPTO_strdup(identity_hint,"ssl/ssl_lib.c",0x1109);
      iVar3 = s[2].error;
      *(char **)(iVar4 + 0x104) = pcVar2;
      iVar3 = *(int *)(iVar3 + 0x104);
      if (iVar3 != 0) {
        iVar3 = 1;
      }
      return iVar3;
    }
    ERR_put_error(0x14,0x111,0x92,"ssl/ssl_lib.c",0x1104);
    return 0;
  }
  CRYPTO_free(*(void **)(s[2].error + 0x104));
  *(undefined4 *)(s[2].error + 0x104) = 0;
  return 1;
}

