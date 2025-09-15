
SSL_CIPHER * SSL_get_current_cipher(SSL *s)

{
  SSL_SESSION *pSVar1;
  
  pSVar1 = s->session;
  if (pSVar1 != (SSL_SESSION *)0x0) {
    pSVar1 = *(SSL_SESSION **)(pSVar1->krb5_client_princ + 0x24);
  }
  return (SSL_CIPHER *)pSVar1;
}

