
SSL_CIPHER * SSL_get_current_cipher(SSL *s)

{
  SSL_CIPHER *pSVar1;
  
  pSVar1 = (SSL_CIPHER *)s[2].tlsext_ticket_expected;
  if (pSVar1 != (SSL_CIPHER *)0x0) {
    pSVar1 = (SSL_CIPHER *)pSVar1[9].id;
  }
  return pSVar1;
}

