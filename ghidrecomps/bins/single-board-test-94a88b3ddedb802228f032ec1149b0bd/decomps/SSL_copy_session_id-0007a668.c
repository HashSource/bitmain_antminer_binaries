
void SSL_copy_session_id(SSL *to,SSL *from)

{
  SSL_SESSION *session;
  SSL_METHOD *pSVar1;
  cert_st *pcVar2;
  
  session = SSL_get_session(from);
  SSL_set_session(to,session);
  if (to->method != from->method) {
    (*to->method->ssl_free)(to);
    pSVar1 = from->method;
    to->method = pSVar1;
    (*pSVar1->ssl_new)(to);
  }
  pcVar2 = to->cert;
  if (from->cert == (cert_st *)0x0) {
    to->cert = (cert_st *)0x0;
  }
  else {
    CRYPTO_add_lock((int *)(from->cert + 0x16c),1,0xd,DAT_0007a704,0x3a6);
    to->cert = from->cert;
  }
  if (pcVar2 != (cert_st *)0x0) {
    ssl_cert_free(pcVar2);
  }
  if (0x20 < from->sid_ctx_length) {
    ERR_put_error(0x14,0xda,0x111,DAT_0007a704,0x1bf);
    return;
  }
  to->sid_ctx_length = from->sid_ctx_length;
  (*(code *)PTR_memcpy_00194250)(to->sid_ctx,from->sid_ctx);
  return;
}

