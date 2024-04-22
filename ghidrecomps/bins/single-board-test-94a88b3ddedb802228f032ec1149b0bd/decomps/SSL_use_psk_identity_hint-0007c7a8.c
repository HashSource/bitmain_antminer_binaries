
int SSL_use_psk_identity_hint(SSL *s,char *identity_hint)

{
  size_t sVar1;
  char *pcVar2;
  SSL_SESSION *pSVar3;
  SSL_SESSION *pSVar4;
  
  if (s != (SSL *)0x0) {
    pSVar4 = s->session;
    if (pSVar4 == (SSL_SESSION *)0x0) {
      return 1;
    }
    if ((identity_hint == (char *)0x0) || (sVar1 = strlen(identity_hint), sVar1 < 0x81)) {
      if ((void *)pSVar4->krb5_client_princ_len != (void *)0x0) {
        CRYPTO_free((void *)pSVar4->krb5_client_princ_len);
        pSVar4 = s->session;
      }
      if (identity_hint != (char *)0x0) {
        pcVar2 = BUF_strdup(identity_hint);
        pSVar3 = s->session;
        pSVar4->krb5_client_princ_len = (uint)pcVar2;
        if (pSVar3->krb5_client_princ_len == 0) {
          return 0;
        }
        return 1;
      }
      pSVar4->krb5_client_princ_len = 0;
      return 1;
    }
    ERR_put_error(0x14,0x111,0x92,DAT_0007c818,0xd50);
  }
  return 0;
}

