
void SSL_free(SSL *ssl)

{
  bool bVar1;
  X509 *a;
  void *ptr;
  _func_3291 **pp_Var2;
  _func_3291 *p_Var3;
  
  if (ssl == (SSL *)0x0) {
    return;
  }
  pp_Var2 = &ssl[3].handshake_func;
  do {
    ExclusiveAccess(pp_Var2);
    p_Var3 = *pp_Var2;
    bVar1 = (bool)hasExclusiveAccess(pp_Var2);
  } while (!bVar1);
  *pp_Var2 = p_Var3 + -1;
  if (p_Var3 == (_func_3291 *)0x1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < (int)(p_Var3 + -1)) {
    return;
  }
  X509_VERIFY_PARAM_free((X509_VERIFY_PARAM *)ssl->write_hash);
  OPENSSL_sk_pop_free(ssl->cert,0xe92f9);
  ssl->cert = (cert_st *)0x0;
  OPENSSL_sk_pop_free(ssl->sid_ctx_length,(undefined *)0x178169);
  a = *(X509 **)(ssl->sid_ctx + 4);
  ssl->sid_ctx_length = 0;
  X509_free(a);
  ssl->sid_ctx[0xc] = 0xff;
  ssl->sid_ctx[0xd] = 0xff;
  ssl->sid_ctx[0xe] = 0xff;
  ssl->sid_ctx[0xf] = 0xff;
  ssl->sid_ctx[0x10] = 0xff;
  ssl->sid_ctx[0x11] = 0xff;
  ssl->sid_ctx[0x12] = 0xff;
  ssl->sid_ctx[0x13] = 0xff;
  ssl->sid_ctx[4] = '\0';
  ssl->sid_ctx[5] = '\0';
  ssl->sid_ctx[6] = '\0';
  ssl->sid_ctx[7] = '\0';
  ssl->sid_ctx[0] = '\0';
  ssl->sid_ctx[1] = '\0';
  ssl->sid_ctx[2] = '\0';
  ssl->sid_ctx[3] = '\0';
  CRYPTO_free_ex_data(0,ssl,(CRYPTO_EX_DATA *)&ssl[3].bbio);
  ssl_free_wbio_buffer(ssl);
  BIO_free_all(ssl->rbio);
  BIO_free_all((BIO *)ssl->method);
  BUF_MEM_free((BUF_MEM *)ssl->hit);
  OPENSSL_sk_free(*(undefined4 *)(ssl->sid_ctx + 0x1c));
  OPENSSL_sk_free(ssl->session);
  OPENSSL_sk_free(ssl->generate_session_id);
  OPENSSL_sk_free(*(undefined4 *)(ssl->sid_ctx + 0x18));
  if (ssl[2].tlsext_ticket_expected != 0) {
    ssl_clear_bad_session(ssl);
    SSL_SESSION_free((SSL_SESSION *)ssl[2].tlsext_ticket_expected);
  }
  SSL_SESSION_free((SSL_SESSION *)ssl[2].tlsext_ecpointformatlist_length);
  CRYPTO_free(ssl[2].tlsext_ecpointformatlist);
  ssl_clear_cipher_ctx(ssl);
  ssl_clear_hash_ctx(ssl[2].sid_ctx + 0x10);
  ssl_clear_hash_ctx(&ssl[2].info_callback);
  ssl_cert_free(ssl[2].error);
  CRYPTO_free((void *)ssl[9].tlsext_status_expected);
  CRYPTO_free(ssl[3].param);
  SSL_CTX_free((SSL_CTX *)ssl[3].max_send_fragment);
  CRYPTO_free((void *)ssl[3].sid_ctx_length);
  CRYPTO_free(*(void **)(ssl[3].sid_ctx + 4));
  CRYPTO_free(*(void **)(ssl[3].sid_ctx + 0xc));
  CRYPTO_free(*(void **)(ssl[3].sid_ctx + 0x14));
  OPENSSL_sk_pop_free(ssl[3].expand,0x177005);
  OPENSSL_sk_pop_free(ssl[3].read_hash,0x14d21d);
  SCT_LIST_free(ssl[3].first_packet);
  CRYPTO_free(ssl[3].cipher_list_by_id);
  CRYPTO_free(ssl[3].enc_write_ctx);
  CRYPTO_free(ssl[3].verify_callback);
  CRYPTO_free((void *)ssl[3].debug);
  ptr = (void *)ssl[3].references;
  if (ptr != (void *)0x0) {
    CRYPTO_free(*(void **)((int)ptr + 0x268));
    ptr = (void *)ssl[3].references;
  }
  CRYPTO_free(ptr);
  CRYPTO_free(ssl[3].tlsext_ocsp_ids);
  EVP_MD_CTX_free(ssl[3].tlsext_ocsp_resplen);
  OPENSSL_sk_pop_free(ssl[3].rwstate,0x177669);
  OPENSSL_sk_pop_free(ssl[3].in_handshake,0x177669);
  OPENSSL_sk_pop_free(ssl[3].rbio,(undefined *)0x178169);
  if (ssl->type != 0) {
    (**(code **)(ssl->type + 0x14))(ssl);
  }
  RECORD_LAYER_release(&ssl[3].tlsext_heartbeat);
  SSL_CTX_free((SSL_CTX *)ssl[3].method);
  ASYNC_WAIT_CTX_free(ssl[9].verify_result);
  CRYPTO_free((void *)ssl[3].error);
  OPENSSL_sk_free(ssl[3].tlsext_debug_cb);
  CRYPTO_THREAD_lock_free(ssl[9].first_packet);
  CRYPTO_free(ssl);
  return;
}

