
void SSL_SESSION_free(SSL_SESSION *ses)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  if (ses == (SSL_SESSION *)0x0) {
    return;
  }
  piVar2 = &ses->references;
  do {
    ExclusiveAccess(piVar2);
    iVar3 = *piVar2;
    bVar1 = (bool)hasExclusiveAccess(piVar2);
  } while (!bVar1);
  *piVar2 = iVar3 + -1;
  if (iVar3 == 1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < iVar3 + -1) {
    return;
  }
  CRYPTO_free_ex_data(2,ses,(CRYPTO_EX_DATA *)&ses->ciphers);
  OPENSSL_cleanse(ses->session_id,0x100);
  OPENSSL_cleanse(ses->krb5_client_princ + 0xbc,0x20);
  X509_free((X509 *)ses->sess_cert);
  OPENSSL_sk_pop_free(ses->peer,(undefined *)0x16e591);
  CRYPTO_free(ses->prev);
  CRYPTO_free(ses->next);
  CRYPTO_free(ses->psk_identity_hint);
  CRYPTO_free(ses->psk_identity);
  CRYPTO_free((void *)ses->tlsext_tick_lifetime_hint);
  CRYPTO_free(ses->tlsext_ellipticcurvelist);
  CRYPTO_free((void *)ses[1].ssl_version);
  CRYPTO_THREAD_lock_free(*(undefined4 *)(ses[1].key_arg + 4));
  CRYPTO_clear_free(ses,0x204,"ssl/ssl_sess.c",0x309);
  return;
}

