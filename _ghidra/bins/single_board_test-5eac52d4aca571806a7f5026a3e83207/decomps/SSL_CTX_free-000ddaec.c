
void SSL_CTX_free(SSL_CTX *param_1)

{
  bool bVar1;
  stack_st_SSL_COMP *psVar2;
  _func_3232 **pp_Var3;
  _func_3232 *p_Var4;
  ulong uVar5;
  
  if (param_1 == (SSL_CTX *)0x0) {
    return;
  }
  pp_Var3 = &param_1->app_verify_callback;
  do {
    ExclusiveAccess(pp_Var3);
    p_Var4 = *pp_Var3;
    bVar1 = (bool)hasExclusiveAccess(pp_Var3);
  } while (!bVar1);
  *pp_Var3 = p_Var4 + -1;
  if (p_Var4 == (_func_3232 *)0x1) {
    DataMemoryBarrier(0x1b);
  }
  else if (0 < (int)(p_Var4 + -1)) {
    return;
  }
  X509_VERIFY_PARAM_free((X509_VERIFY_PARAM *)param_1->tlsext_servername_callback);
  CRYPTO_free(param_1[1].rsa_md5);
  param_1[1].rsa_md5 = (EVP_MD *)0x0;
  CRYPTO_free(param_1[1].md5);
  uVar5 = param_1->session_cache_size;
  param_1[1].md5 = (EVP_MD *)0x0;
  *(undefined1 *)&param_1[1].sha1 = 0;
  if (uVar5 != 0) {
    SSL_CTX_flush_sessions(param_1,0);
  }
  CRYPTO_free_ex_data(1,param_1,(CRYPTO_EX_DATA *)&param_1->md5);
  OPENSSL_LH_free(param_1->session_cache_size);
  X509_STORE_free((X509_STORE *)param_1->sessions);
  CTLOG_STORE_free(*(undefined4 *)param_1->tlsext_tick_key_name);
  OPENSSL_sk_free(param_1->cipher_list);
  OPENSSL_sk_free(param_1->cipher_list_by_id);
  OPENSSL_sk_free(param_1->cert_store);
  ssl_cert_free(param_1->verify_mode);
  OPENSSL_sk_pop_free(param_1->options,0x169841);
  OPENSSL_sk_pop_free(param_1->mode,0x169841);
  OPENSSL_sk_pop_free(param_1->comp_methods,0x16a341);
  psVar2 = param_1[1].comp_methods;
  param_1->info_callback = (_func_3236 *)0x0;
  OPENSSL_sk_free(psVar2);
  SSL_CTX_SRP_CTX_free(param_1);
  ENGINE_finish(*(ENGINE **)(param_1->tlsext_tick_hmac_key + 0xc));
  CRYPTO_free(param_1->next_protos_advertised_cb);
  CRYPTO_free(param_1->next_proto_select_cb);
  CRYPTO_free(param_1[1].method);
  CRYPTO_secure_free(param_1->tlsext_opaque_prf_input_callback_arg,"ssl/ssl_lib.c",0xcd9);
  CRYPTO_THREAD_lock_free(param_1[1].client_CA);
  CRYPTO_free(param_1);
  return;
}

