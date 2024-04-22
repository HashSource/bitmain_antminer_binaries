
X509 * SSL_SESSION_get0_peer(SSL_SESSION *s)

{
  return *(X509 **)(s->krb5_client_princ + 0xc);
}

