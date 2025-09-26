
SSL_SESSION * SSL_get1_session(SSL *ssl)

{
  SSL_SESSION *pSVar1;
  
  CRYPTO_THREAD_read_lock(ssl[9].first_packet);
  pSVar1 = (SSL_SESSION *)ssl[2].tlsext_ticket_expected;
  if (pSVar1 != (SSL_SESSION *)0x0) {
    SSL_SESSION_up_ref(pSVar1);
  }
  CRYPTO_THREAD_unlock(ssl[9].first_packet);
  return pSVar1;
}

