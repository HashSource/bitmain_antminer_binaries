
SSL_CTX * SSL_CTX_new(SSL_METHOD *meth)

{
  int iVar1;
  SSL_CTX *ptr;
  _func_3229 *p_Var2;
  stack_st_X509_NAME *psVar3;
  ulong uVar4;
  X509_STORE *pXVar5;
  X509_VERIFY_PARAM *pXVar6;
  EVP_MD *pEVar7;
  void *pvVar8;
  stack_st_SSL_COMP *psVar9;
  _func_3218 *p_Var10;
  uint uVar11;
  
  if (meth == (SSL_METHOD *)0x0) {
    ERR_put_error(0x14,0xa9,0xc4,"ssl/ssl_lib.c",0xbdc);
    return (SSL_CTX *)0x0;
  }
  iVar1 = OPENSSL_init_ssl(0x200000,0,0);
  if (iVar1 == 0) {
    return (SSL_CTX *)0x0;
  }
  iVar1 = SSL_get_ex_data_X509_STORE_CTX_idx();
  if (iVar1 < 0) {
    ptr = (SSL_CTX *)0x0;
    ERR_put_error(0x14,0xa9,0x10d,"ssl/ssl_lib.c",0xbe4);
  }
  else {
    ptr = (SSL_CTX *)CRYPTO_zalloc(0x250,"ssl/ssl_lib.c",0xbe7);
    if (ptr != (SSL_CTX *)0x0) {
      ptr->cert = (cert_st *)&DAT_00000004;
      ptr->session_timeout = 2;
      ptr->session_cache_head = (ssl_session_st *)0x5000;
      ptr->method = meth;
      p_Var10 = meth->get_timeout;
      ptr->read_ahead = 0;
      ptr->msg_callback = (_func_3237 *)0x0;
      p_Var2 = (_func_3229 *)(*p_Var10)();
      ptr->new_session_cb = p_Var2;
      DataMemoryBarrier(0x1b);
      ptr->app_verify_callback = (_func_3232 *)0x1;
      DataMemoryBarrier(0x1b);
      psVar3 = (stack_st_X509_NAME *)CRYPTO_THREAD_lock_new();
      ptr[1].client_CA = psVar3;
      if (psVar3 == (stack_st_X509_NAME *)0x0) {
        ERR_put_error(0x14,0xa9,0x41,"ssl/ssl_lib.c",0xbf6);
        CRYPTO_free(ptr);
        return (SSL_CTX *)0x0;
      }
      ptr->sid_ctx[8] = '\0';
      ptr->sid_ctx[9] = '\0';
      ptr->sid_ctx[10] = '\0';
      ptr->sid_ctx[0xb] = '\0';
      ptr->msg_callback_arg = (void *)0x19000;
      iVar1 = ssl_cert_new();
      ptr->verify_mode = iVar1;
      if (iVar1 != 0) {
        uVar4 = OPENSSL_LH_new(0xe9329,0xe9351);
        ptr->session_cache_size = uVar4;
        if (uVar4 != 0) {
          pXVar5 = X509_STORE_new();
          ptr->sessions = (lhash_st_SSL_SESSION *)pXVar5;
          if (pXVar5 != (X509_STORE *)0x0) {
            iVar1 = CTLOG_STORE_new();
            *(int *)ptr->tlsext_tick_key_name = iVar1;
            if ((iVar1 != 0) &&
               (iVar1 = SSL_CTX_set_ciphersuites
                                  (ptr,
                                   "TLS_AES_256_GCM_SHA384:TLS_CHACHA20_POLY1305_SHA256:TLS_AES_128_GCM_SHA256"
                                  ), iVar1 != 0)) {
              iVar1 = ssl_create_cipher_list
                                (ptr->method,ptr->cert_store,&ptr->cipher_list,
                                 &ptr->cipher_list_by_id,"ALL:!COMPLEMENTOFDEFAULT:!eNULL",
                                 ptr->verify_mode);
              if ((iVar1 == 0) || (iVar1 = OPENSSL_sk_num(ptr->cipher_list), iVar1 < 1)) {
                ERR_put_error(0x14,0xa9,0xa1,"ssl/ssl_lib.c",0xc13);
                goto LAB_000ebca0;
              }
              pXVar6 = X509_VERIFY_PARAM_new();
              ptr->tlsext_servername_callback = (_func_3239 *)pXVar6;
              if (pXVar6 != (X509_VERIFY_PARAM *)0x0) {
                pEVar7 = EVP_get_digestbyname("ssl3-md5");
                ptr->sha1 = pEVar7;
                if (pEVar7 == (EVP_MD *)0x0) {
                  ERR_put_error(0x14,0xa9,0xf2,"ssl/ssl_lib.c",0xc1c);
                  goto LAB_000ebca0;
                }
                pEVar7 = EVP_get_digestbyname("ssl3-sha1");
                ptr->extra_certs = (stack_st_X509 *)pEVar7;
                if (pEVar7 == (EVP_MD *)0x0) {
                  ERR_put_error(0x14,0xa9,0xf3,"ssl/ssl_lib.c",0xc20);
                  goto LAB_000ebca0;
                }
                uVar4 = OPENSSL_sk_new_null();
                ptr->options = uVar4;
                if (uVar4 != 0) {
                  uVar4 = OPENSSL_sk_new_null();
                  ptr->mode = uVar4;
                  if ((uVar4 != 0) &&
                     (iVar1 = CRYPTO_new_ex_data(1,ptr,(CRYPTO_EX_DATA *)&ptr->md5), iVar1 != 0)) {
                    pvVar8 = (void *)CRYPTO_secure_zalloc(0x40,"ssl/ssl_lib.c",0xc2d);
                    ptr->tlsext_opaque_prf_input_callback_arg = pvVar8;
                    if (pvVar8 != (void *)0x0) {
                      if (-1 < *(int *)(meth->ssl3_enc + 0x30) << 0x1c) {
                        psVar9 = SSL_COMP_get_compression_methods();
                        ptr->info_callback = (_func_3236 *)psVar9;
                      }
                      ptr->tlsext_tick_hmac_key[0] = '\0';
                      ptr->tlsext_tick_hmac_key[1] = '@';
                      ptr->tlsext_tick_hmac_key[2] = '\0';
                      ptr->tlsext_tick_hmac_key[3] = '\0';
                      ptr->tlsext_tick_key_name[0xc] = '\0';
                      ptr->tlsext_tick_key_name[0xd] = '@';
                      ptr->tlsext_tick_key_name[0xe] = '\0';
                      ptr->tlsext_tick_key_name[0xf] = '\0';
                      iVar1 = RAND_bytes((uchar *)&ptr->tlsext_ticket_key_cb,0x10);
                      if (((iVar1 < 1) ||
                          (iVar1 = RAND_priv_bytes(ptr->tlsext_opaque_prf_input_callback_arg,0x20),
                          iVar1 < 1)) ||
                         (iVar1 = RAND_priv_bytes((int)ptr->tlsext_opaque_prf_input_callback_arg +
                                                  0x20), iVar1 < 1)) {
                        ptr->max_cert_list = ptr->max_cert_list | 0x4000;
                      }
                      iVar1 = RAND_priv_bytes(&ptr[1].session_cache_head,0x20);
                      if ((0 < iVar1) && (iVar1 = SSL_CTX_SRP_CTX_init(ptr), iVar1 != 0)) {
                        uVar11 = ptr->max_cert_list;
                        ptr->freelist_max_len = 0xffffffff;
                        ptr[1].mode = 0;
                        ptr[1].max_cert_list = 0x4000;
                        ptr->max_cert_list = uVar11 | 0x120004;
                        ptr[1].sid_ctx[0] = '\x02';
                        ptr[1].sid_ctx[1] = '\0';
                        ptr[1].sid_ctx[2] = '\0';
                        ptr[1].sid_ctx[3] = '\0';
                        ssl_ctx_system_config(ptr);
                        return ptr;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ERR_put_error(0x14,0xa9,0x41,"ssl/ssl_lib.c",0xc8e);
LAB_000ebca0:
  SSL_CTX_free(ptr);
  return (SSL_CTX *)0x0;
}

