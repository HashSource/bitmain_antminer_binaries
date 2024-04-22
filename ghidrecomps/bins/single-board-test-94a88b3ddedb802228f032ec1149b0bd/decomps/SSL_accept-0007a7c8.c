
int SSL_accept(SSL *ssl)

{
  int iVar1;
  _func_3198 *p_Var2;
  
  if (ssl->handshake_func == (_func_3291 *)0x0) {
    ssl->shutdown = 0;
    p_Var2 = ssl->method->ssl_accept;
    ssl->server = 1;
    ssl->state = 0x6000;
    ssl->handshake_func = (_func_3291 *)p_Var2;
    if (ssl->enc_read_ctx != (EVP_CIPHER_CTX *)0x0) {
      EVP_CIPHER_CTX_cleanup(ssl->enc_read_ctx);
      CRYPTO_free(ssl->enc_read_ctx);
      ssl->enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
    }
    if (ssl->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
      EVP_CIPHER_CTX_cleanup(ssl->enc_write_ctx);
      CRYPTO_free(ssl->enc_write_ctx);
      ssl->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
    if (ssl->expand != (COMP_CTX *)0x0) {
      COMP_CTX_free(ssl->expand);
      ssl->expand = (COMP_CTX *)0x0;
    }
    if (ssl->compress != (COMP_CTX *)0x0) {
      COMP_CTX_free(ssl->compress);
      ssl->compress = (COMP_CTX *)0x0;
    }
    if (ssl->read_hash != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ssl->read_hash);
    }
    ssl->read_hash = (EVP_MD_CTX *)0x0;
    if (ssl->write_hash != (EVP_MD_CTX *)0x0) {
      EVP_MD_CTX_destroy(ssl->write_hash);
    }
    ssl->write_hash = (EVP_MD_CTX *)0x0;
  }
  iVar1 = (*ssl->method->ssl_accept)(ssl);
  return iVar1;
}

