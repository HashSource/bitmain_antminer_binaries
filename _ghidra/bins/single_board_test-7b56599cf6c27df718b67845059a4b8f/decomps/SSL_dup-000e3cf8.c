
SSL * SSL_dup(SSL *ssl)

{
  bool bVar1;
  int iVar2;
  SSL_CTX *pSVar3;
  SSL *s;
  int extraout_r0;
  X509 *a;
  cert_st *pcVar4;
  undefined1 *puVar5;
  long larg;
  callback *callback;
  cb *cb;
  SSL_SESSION *pSVar6;
  X509_NAME *pXVar7;
  X509_STORE_CTX *extraout_r1;
  int type;
  EVP_CIPHER_CTX *pEVar8;
  undefined4 uVar9;
  EVP_MD_CTX *pEVar10;
  int val;
  _func_3296 *p_Var11;
  _func_3291 **pp_Var12;
  SSL_METHOD *pSVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  iVar2 = SSL_in_init();
  if ((iVar2 == 0) || (iVar2 = SSL_in_before(ssl), iVar2 == 0)) {
    pp_Var12 = &ssl[3].handshake_func;
    do {
      ExclusiveAccess(pp_Var12);
      bVar1 = (bool)hasExclusiveAccess(pp_Var12);
    } while (!bVar1);
    *pp_Var12 = *pp_Var12 + 1;
    return ssl;
  }
  pSVar3 = SSL_get_SSL_CTX(ssl);
  s = SSL_new(pSVar3);
  if (s == (SSL *)0x0) {
    return (SSL *)0x0;
  }
  if (ssl[2].tlsext_ticket_expected == 0) {
    iVar2 = SSL_set_ssl_method(s,(SSL_METHOD *)ssl->type);
    if (iVar2 == 0) goto LAB_000e3e04;
    if (ssl[2].error != 0) {
      ssl_cert_free(s[2].error);
      iVar2 = ssl_cert_dup(ssl[2].error);
      s[2].error = iVar2;
      if (iVar2 == 0) goto LAB_000e3e04;
    }
    iVar2 = SSL_set_session_id_context
                      (s,(uchar *)&ssl[2].tlsext_hostname,(uint)ssl[2].tlsext_debug_arg);
  }
  else {
    SSL_copy_session_id(s,ssl);
    iVar2 = extraout_r0;
  }
  if (iVar2 != 0) {
    iVar2 = OPENSSL_sk_num(ssl->cert);
    if (0 < iVar2) {
      iVar15 = 0;
      iVar2 = OPENSSL_sk_num(ssl->cert);
      OPENSSL_sk_pop_free(s->cert,0xdf721);
      s->cert = (cert_st *)0x0;
      OPENSSL_sk_pop_free(s->sid_ctx_length,(undefined *)0x16e591);
      a = *(X509 **)(s->sid_ctx + 4);
      s->sid_ctx_length = 0;
      X509_free(a);
      pSVar13 = s[3].method;
      uVar9 = *(undefined4 *)(ssl->sid_ctx + 0x14);
      s->sid_ctx[4] = '\0';
      s->sid_ctx[5] = '\0';
      s->sid_ctx[6] = '\0';
      s->sid_ctx[7] = '\0';
      s->sid_ctx[0] = '\0';
      s->sid_ctx[1] = '\0';
      s->sid_ctx[2] = '\0';
      s->sid_ctx[3] = '\0';
      s->compress = (COMP_CTX *)&pSVar13[4].ssl_get_message;
      *(undefined4 *)(s->sid_ctx + 0x14) = uVar9;
      s->sid_ctx[0xc] = 0xff;
      s->sid_ctx[0xd] = 0xff;
      s->sid_ctx[0xe] = 0xff;
      s->sid_ctx[0xf] = 0xff;
      s->sid_ctx[0x10] = 0xff;
      s->sid_ctx[0x11] = 0xff;
      s->sid_ctx[0x12] = 0xff;
      s->sid_ctx[0x13] = 0xff;
      pcVar4 = (cert_st *)OPENSSL_sk_new_reserve(0,iVar2);
      s->cert = pcVar4;
      if (pcVar4 == (cert_st *)0x0) {
        ERR_put_error(0x14,0x193,0x41,"ssl/ssl_lib.c",0xe0);
        goto LAB_000e3e04;
      }
      if (0 < iVar2) {
        do {
          puVar5 = (undefined1 *)OPENSSL_sk_value(ssl->cert,iVar15);
          iVar15 = iVar15 + 1;
          iVar14 = SSL_dane_tlsa_add(s,*puVar5,puVar5[1],puVar5[2],*(undefined4 *)(puVar5 + 4),
                                     *(undefined4 *)(puVar5 + 8));
          if (iVar14 < 1) goto LAB_000e3e04;
        } while (iVar2 != iVar15);
      }
    }
    iVar15 = ssl[3].quiet_shutdown;
    iVar2 = ssl[3].shutdown;
    iVar16 = ssl[3].server;
    s->version = ssl->version;
    iVar14 = ssl[3].new_session;
    s[3].quiet_shutdown = iVar15;
    s[3].shutdown = iVar2;
    s[3].new_session = iVar14;
    s[3].server = iVar16;
    larg = SSL_ctrl(ssl,0x32,0,(void *)0x0);
    SSL_ctrl(s,0x33,larg,(void *)0x0);
    iVar2 = SSL_get_read_ahead(ssl);
    SSL_set_read_ahead(s,iVar2);
    pEVar10 = ssl->read_hash;
    s->expand = ssl->expand;
    s->read_hash = pEVar10;
    iVar2 = SSL_get_verify_mode(ssl);
    callback = (callback *)SSL_get_verify_callback((int)ssl,extraout_r1);
    SSL_set_verify(s,iVar2,callback);
    iVar2 = SSL_get_verify_depth(ssl);
    SSL_set_verify_depth(s,iVar2);
    s[2].tlsext_ellipticcurvelist = ssl[2].tlsext_ellipticcurvelist;
    SSL_get_info_callback(ssl,type,val);
    SSL_set_info_callback(s,cb);
    iVar2 = CRYPTO_dup_ex_data(0,(CRYPTO_EX_DATA *)&s[3].bbio,(CRYPTO_EX_DATA *)&ssl[3].bbio);
    if (iVar2 != 0) {
      iVar2 = ssl->rwstate;
      s->in_handshake = ssl->in_handshake;
      if (iVar2 != 0) {
        if (ssl->in_handshake == 0) {
          SSL_set_connect_state(s);
        }
        else {
          SSL_set_accept_state(s);
        }
      }
      pEVar8 = ssl->enc_write_ctx;
      p_Var11 = ssl[9].psk_server_callback;
      pSVar3 = ssl[9].ctx;
      s->new_session = ssl->new_session;
      s->enc_write_ctx = pEVar8;
      s[9].psk_server_callback = p_Var11;
      s[9].ctx = pSVar3;
      X509_VERIFY_PARAM_inherit
                ((X509_VERIFY_PARAM *)s->write_hash,(X509_VERIFY_PARAM *)ssl->write_hash);
      if (*(int *)(ssl->sid_ctx + 0x1c) != 0) {
        iVar2 = OPENSSL_sk_dup();
        *(int *)(s->sid_ctx + 0x1c) = iVar2;
        if (iVar2 == 0) goto LAB_000e3e04;
      }
      if (ssl->session != (SSL_SESSION *)0x0) {
        pSVar6 = (SSL_SESSION *)OPENSSL_sk_dup();
        s->session = pSVar6;
        if (pSVar6 == (SSL_SESSION *)0x0) goto LAB_000e3e04;
      }
      iVar2 = ssl[3].rwstate;
      if (iVar2 == 0) {
        s[3].rwstate = 0;
LAB_000e3f64:
        iVar2 = ssl[3].in_handshake;
        if (iVar2 == 0) {
          s[3].in_handshake = 0;
          return s;
        }
        iVar15 = OPENSSL_sk_new_null();
        if (iVar15 != 0) {
          iVar14 = 0;
          do {
            iVar16 = OPENSSL_sk_num(iVar2);
            if (iVar16 <= iVar14) {
              s[3].in_handshake = iVar15;
              return s;
            }
            pXVar7 = (X509_NAME *)OPENSSL_sk_value(iVar2,iVar14);
            pXVar7 = X509_NAME_dup(pXVar7);
            if (pXVar7 == (X509_NAME *)0x0) goto LAB_000e4010;
            iVar16 = OPENSSL_sk_insert(iVar15,pXVar7,iVar14);
            iVar14 = iVar14 + 1;
          } while (iVar16 != 0);
          X509_NAME_free(pXVar7);
LAB_000e4010:
          OPENSSL_sk_pop_free(iVar15,(undefined *)0x16da91);
        }
      }
      else {
        iVar15 = OPENSSL_sk_new_null();
        if (iVar15 != 0) {
          iVar14 = 0;
          do {
            iVar16 = OPENSSL_sk_num(iVar2);
            if (iVar16 <= iVar14) {
              s[3].rwstate = iVar15;
              goto LAB_000e3f64;
            }
            pXVar7 = (X509_NAME *)OPENSSL_sk_value(iVar2,iVar14);
            pXVar7 = X509_NAME_dup(pXVar7);
            if (pXVar7 == (X509_NAME *)0x0) goto LAB_000e3fb4;
            iVar16 = OPENSSL_sk_insert(iVar15,pXVar7,iVar14);
            iVar14 = iVar14 + 1;
          } while (iVar16 != 0);
          X509_NAME_free(pXVar7);
LAB_000e3fb4:
          OPENSSL_sk_pop_free(iVar15,(undefined *)0x16da91);
        }
      }
    }
  }
LAB_000e3e04:
  SSL_free(s);
  return (SSL *)0x0;
}

