
int SSL_clear(SSL *s)

{
  int iVar1;
  BUF_MEM *a;
  X509 *a_00;
  EVP_MD_CTX *pEVar2;
  SSL_METHOD *pSVar3;
  BUF_MEM *pBVar4;
  int iVar5;
  char *pcVar6;
  
  if (s->type == 0) {
    ERR_put_error(0x14,0xa4,0xbc,"ssl/ssl_lib.c",0x244);
    return 0;
  }
  iVar1 = ssl_clear_bad_session();
  if (iVar1 != 0) {
    SSL_SESSION_free((SSL_SESSION *)s[2].tlsext_ticket_expected);
    s[2].tlsext_ticket_expected = 0;
  }
  SSL_SESSION_free((SSL_SESSION *)s[2].tlsext_ecpointformatlist_length);
  s[2].tlsext_ecpointformatlist_length = 0;
  CRYPTO_free(s[2].tlsext_ecpointformatlist);
  pcVar6 = s[3].tlsext_hostname;
  s[2].tlsext_ecpointformatlist = (uchar *)0x0;
  s[2].tlsext_ellipticcurvelist_length = 0;
  s[2].tlsext_debug_cb = (_func_3297 *)0x0;
  s[9].max_send_fragment = 0;
  s[2].tlsext_heartbeat = 0;
  s->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
  s->new_session = 0;
  if (pcVar6 == (char *)0x0) {
    ossl_statem_clear(s);
    a = (BUF_MEM *)s->hit;
    pBVar4 = *(BUF_MEM **)s->type;
    s->bbio = (BIO *)0x1;
    s->version = (int)pBVar4;
    s[3].init_buf = pBVar4;
    BUF_MEM_free(a);
    s->hit = 0;
    ssl_clear_cipher_ctx(s);
    ssl_clear_hash_ctx(s[2].sid_ctx + 0x10);
    ssl_clear_hash_ctx(&s[2].info_callback);
    s[3].rstate = 0;
    s[3].servername_done = -1;
    EVP_MD_CTX_free(s[3].tlsext_ocsp_resplen);
    a_00 = *(X509 **)(s->sid_ctx + 4);
    s->sid_ctx[0xc] = 0xff;
    s->sid_ctx[0xd] = 0xff;
    s->sid_ctx[0xe] = 0xff;
    s->sid_ctx[0xf] = 0xff;
    s->sid_ctx[0x10] = 0xff;
    s->sid_ctx[0x11] = 0xff;
    s->sid_ctx[0x12] = 0xff;
    s->sid_ctx[0x13] = 0xff;
    s[3].tlsext_ocsp_resplen = 0;
    X509_free(a_00);
    pEVar2 = s->write_hash;
    s->sid_ctx[4] = '\0';
    s->sid_ctx[5] = '\0';
    s->sid_ctx[6] = '\0';
    s->sid_ctx[7] = '\0';
    s->sid_ctx[0] = '\0';
    s->sid_ctx[1] = '\0';
    s->sid_ctx[2] = '\0';
    s->sid_ctx[3] = '\0';
    X509_VERIFY_PARAM_move_peername(pEVar2,0);
    CRYPTO_free((void *)s[9].tlsext_status_expected);
    pSVar3 = s[3].method;
    iVar5 = s->type;
    s[9].tlsext_status_expected = 0;
    iVar1 = pSVar3->version;
    s[9].tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)0x0;
    if (iVar5 == iVar1) {
      iVar1 = (**(code **)(iVar5 + 0x10))(s);
    }
    else {
      (**(code **)(iVar5 + 0x14))(s);
      iVar1 = (s[3].method)->version;
      s->type = iVar1;
      iVar1 = (**(code **)(iVar1 + 0xc))(s);
    }
    if (iVar1 != 0) {
      RECORD_LAYER_clear(&s[3].tlsext_heartbeat);
    }
    return (uint)(iVar1 != 0);
  }
  ERR_put_error(0x14,0xa4,0x44,"ssl/ssl_lib.c",0x259);
  return 0;
}

