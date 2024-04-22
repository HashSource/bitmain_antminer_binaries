
int SSL_clear(SSL *s)

{
  int iVar1;
  int iVar2;
  SSL_METHOD *pSVar3;
  
  if (s->method == (SSL_METHOD *)0x0) {
    ERR_put_error(0x14,0xa4,0xbc,DAT_00079e20,0xc2);
    iVar1 = 0;
  }
  else {
    iVar1 = ssl_clear_bad_session();
    if (iVar1 != 0) {
      SSL_SESSION_free(s->session);
      s->session = (SSL_SESSION *)0x0;
    }
    iVar1 = 0;
    s->error = 0;
    s->hit = 0;
    s->shutdown = 0;
    if (s->tlsext_hb_seq == 0) {
      iVar1 = s->method->version;
      if (s->server == 0) {
        iVar2 = 0x5000;
      }
      else {
        iVar2 = 0x6000;
      }
      s->type = 0;
      s->state = iVar2;
      s->version = iVar1;
      s->first_packet = iVar1;
      s->rwstate = 1;
      s->rstate = 0xf0;
      if (s->init_buf != (BUF_MEM *)0x0) {
        BUF_MEM_free(s->init_buf);
        s->init_buf = (BUF_MEM *)0x0;
      }
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
      s->max_cert_list = 0;
      if ((s->in_handshake == 0) && (s->session == (SSL_SESSION *)0x0)) {
        pSVar3 = s->method;
        if (pSVar3 != *(SSL_METHOD **)s->psk_server_callback) {
          (*pSVar3->ssl_free)(s);
          pSVar3 = *(SSL_METHOD **)s->psk_server_callback;
          s->method = pSVar3;
          iVar1 = (*pSVar3->ssl_new)(s);
          if (iVar1 == 0) {
            return 0;
          }
          return 1;
        }
      }
      else {
        pSVar3 = s->method;
      }
      (*pSVar3->ssl_clear)(s);
      iVar1 = 1;
    }
    else {
      ERR_put_error(0x14,0xa4,0x44,DAT_00079e20,0xdc);
    }
  }
  return iVar1;
}

