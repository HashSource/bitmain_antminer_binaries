
X509 * SSL_get_certificate(SSL *ssl)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)ssl->cert;
  if (pXVar1 != (X509 *)0x0) {
    pXVar1 = (X509 *)pXVar1->cert_info->version;
  }
  return pXVar1;
}

