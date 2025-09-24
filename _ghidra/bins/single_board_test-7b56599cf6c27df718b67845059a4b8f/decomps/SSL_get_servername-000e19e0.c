
char * SSL_get_servername(SSL *s,int type)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  
  if (s->rwstate == 0) {
    if (type != 0) {
      return (char *)0x0;
    }
  }
  else {
    if (type != 0) {
      return (char *)0x0;
    }
    if (s->in_handshake != 0) {
      if ((s->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) &&
         ((*(int *)(((int *)s->type)[0x19] + 0x30) << 0x1c < 0 ||
          (iVar1 = *(int *)s->type, iVar1 == 0x10000 || iVar1 < 0x304)))) {
        return *(char **)(s[2].tlsext_ticket_expected + 0x1cc);
      }
      return (char *)s[3].param;
    }
  }
  iVar1 = SSL_in_before();
  if (iVar1 == 0) {
    if ((((*(int *)(((int *)s->type)[0x19] + 0x30) << 0x1c < 0) ||
         (iVar1 = *(int *)s->type, iVar1 < 0x304 || iVar1 == 0x10000)) &&
        (s->enc_write_ctx != (EVP_CIPHER_CTX *)0x0)) &&
       (pcVar2 = *(char **)(s[2].tlsext_ticket_expected + 0x1cc), pcVar2 != (char *)0x0)) {
      return pcVar2;
    }
    return (char *)s[3].param;
  }
  if (s[3].param == (X509_VERIFY_PARAM *)0x0) {
    piVar3 = (int *)s[2].tlsext_ticket_expected;
    if (piVar3 == (int *)0x0) {
      return (char *)0x0;
    }
    if (*piVar3 != 0x304) {
      return (char *)piVar3[0x73];
    }
  }
  return (char *)s[3].param;
}

