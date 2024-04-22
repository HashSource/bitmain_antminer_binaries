
int SSL_connect(SSL *ssl)

{
  int iVar1;
  _func_3199 *p_Var2;
  
  if (ssl->handshake_func == (_func_3291 *)0x0) {
    ssl->server = 0;
    p_Var2 = ssl->method->ssl_connect;
    ssl->shutdown = 0;
    ssl->state = 0x5000;
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
  iVar1 = (*ssl->method->ssl_connect)(ssl);
  return iVar1;
}

