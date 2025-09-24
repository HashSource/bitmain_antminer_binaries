
X509 * SSL_get_peer_certificate(SSL *s)

{
  X509 *pXVar1;
  
  if (s == (SSL *)0x0) {
    pXVar1 = (X509 *)0x0;
  }
  else {
    pXVar1 = (X509 *)s[2].tlsext_ticket_expected;
    if ((pXVar1 != (X509 *)0x0) && (pXVar1 = (X509 *)pXVar1[3].nc, pXVar1 != (X509 *)0x0)) {
      X509_up_ref(pXVar1);
    }
  }
  return pXVar1;
}

