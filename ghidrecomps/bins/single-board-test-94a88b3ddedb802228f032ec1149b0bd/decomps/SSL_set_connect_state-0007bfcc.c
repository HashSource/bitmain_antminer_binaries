
void SSL_set_connect_state(SSL *s)

{
  _func_3199 *p_Var1;
  
  p_Var1 = s->method->ssl_connect;
  s->state = 0x5000;
  s->server = 0;
  s->shutdown = 0;
  s->handshake_func = (_func_3291 *)p_Var1;
  if (s->enc_read_ctx != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_cleanup(s->enc_read_ctx);
    CRYPTO_free(s->enc_read_ctx);
    s->enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
  }
  if (s->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_cleanup(s->enc_write_ctx);
    CRYPTO_free(s->enc_write_ctx);
    s->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
  }
  if (s->expand != (COMP_CTX *)0x0) {
    COMP_CTX_free(s->expand);
    s->expand = (COMP_CTX *)0x0;
  }
  if (s->compress != (COMP_CTX *)0x0) {
    COMP_CTX_free(s->compress);
    s->compress = (COMP_CTX *)0x0;
  }
  if (s->read_hash != (EVP_MD_CTX *)0x0) {
    EVP_MD_CTX_destroy(s->read_hash);
  }
  s->read_hash = (EVP_MD_CTX *)0x0;
  if (s->write_hash != (EVP_MD_CTX *)0x0) {
    EVP_MD_CTX_destroy(s->write_hash);
  }
  s->write_hash = (EVP_MD_CTX *)0x0;
  return;
}

