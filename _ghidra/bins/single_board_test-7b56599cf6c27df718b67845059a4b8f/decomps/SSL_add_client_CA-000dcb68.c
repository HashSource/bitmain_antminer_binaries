
int SSL_add_client_CA(SSL *ssl,X509 *x)

{
  X509_NAME *pXVar1;
  int iVar2;
  
  if (x != (X509 *)0x0) {
    if (ssl[3].in_handshake == 0) {
      iVar2 = OPENSSL_sk_new_null();
      ssl[3].in_handshake = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
    }
    pXVar1 = X509_get_subject_name(x);
    pXVar1 = X509_NAME_dup(pXVar1);
    if (pXVar1 != (X509_NAME *)0x0) {
      iVar2 = OPENSSL_sk_push(ssl[3].in_handshake,pXVar1);
      if (iVar2 == 0) {
        X509_NAME_free(pXVar1);
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

