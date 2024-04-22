
SSL_SESSION * SSL_get1_session(SSL *ssl)

{
  SSL_SESSION *pSVar1;
  
  CRYPTO_lock(9,0xe,DAT_0007ea0c,0xa5);
  pSVar1 = ssl->session;
  if (pSVar1 != (SSL_SESSION *)0x0) {
    *(int *)(pSVar1->krb5_client_princ + 0x14) = *(int *)(pSVar1->krb5_client_princ + 0x14) + 1;
  }
  CRYPTO_lock(10,0xe,DAT_0007ea0c,0xa9);
  return pSVar1;
}

