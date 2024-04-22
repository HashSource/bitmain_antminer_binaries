
void Curl_ossl_session_free(SSL_SESSION *ses)

{
  int iVar1;
  
  if (ses != (SSL_SESSION *)0x0) {
    iVar1 = CRYPTO_add_lock((int *)(ses->krb5_client_princ + 0x14),-1,0xe,DAT_0007f438,0x352);
    if (iVar1 < 1) {
      SSL_SESSION_free_part_0(ses);
      return;
    }
  }
  return;
}

