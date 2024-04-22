
X509 * SSL_get_peer_certificate(SSL *s)

{
  SSL_SESSION *pSVar1;
  
  if (s == (SSL *)0x0) {
    pSVar1 = (SSL_SESSION *)0x0;
  }
  else {
    pSVar1 = s->session;
    if ((pSVar1 != (SSL_SESSION *)0x0) &&
       (pSVar1 = *(SSL_SESSION **)(pSVar1->krb5_client_princ + 0xc), pSVar1 != (SSL_SESSION *)0x0))
    {
      CRYPTO_add_lock(&pSVar1->master_key_length,1,3,DAT_0007a650,0x379);
    }
  }
  return (X509 *)pSVar1;
}

