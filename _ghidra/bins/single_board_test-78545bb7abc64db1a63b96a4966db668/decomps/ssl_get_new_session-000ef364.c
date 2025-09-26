
undefined4 ssl_get_new_session(SSL *param_1,int param_2)

{
  SSL_SESSION *ses;
  long lVar1;
  void *__n;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  ses = SSL_SESSION_new();
  if (ses == (SSL_SESSION *)0x0) {
    ossl_statem_fatal(param_1,0x50,0xb5,0x41,"ssl/ssl_sess.c",0x172);
    return 0;
  }
  iVar2 = *(int *)(param_1[3].max_send_fragment + 0x28);
  if (iVar2 == 0) {
    lVar1 = SSL_get_default_timeout(param_1);
    ses->timeout = lVar1;
  }
  else {
    ses->timeout = iVar2;
  }
  SSL_SESSION_free((SSL_SESSION *)param_1[2].tlsext_ticket_expected);
  param_1[2].tlsext_ticket_expected = 0;
  if (param_2 == 0) {
    ses->krb5_client_princ[0xb8] = '\0';
    ses->krb5_client_princ[0xb9] = '\0';
    ses->krb5_client_princ[0xba] = '\0';
    ses->krb5_client_princ[0xbb] = '\0';
  }
  else {
    if (((*(uint *)(((int *)param_1->type)[0x19] + 0x30) & 8) == 0) &&
       (iVar2 = *(int *)param_1->type, iVar2 != 0x10000 && 0x303 < iVar2)) {
      __n = param_1[2].tlsext_debug_arg;
      ses->krb5_client_princ[0xb8] = '\0';
      ses->krb5_client_princ[0xb9] = '\0';
      ses->krb5_client_princ[0xba] = '\0';
      ses->krb5_client_princ[0xbb] = '\0';
      goto joined_r0x000ef40c;
    }
    iVar2 = ssl_generate_session_id(param_1,ses);
    if (iVar2 == 0) {
      SSL_SESSION_free(ses);
      return 0;
    }
  }
  __n = param_1[2].tlsext_debug_arg;
joined_r0x000ef40c:
  if (__n < (void *)0x21) {
    memcpy(ses->krb5_client_princ + 0xe0,&param_1[2].tlsext_hostname,(size_t)__n);
    iVar2 = param_1->version;
    iVar3 = *(int *)param_1->mac_flags;
    *(void **)(ses->krb5_client_princ + 0xdc) = param_1[2].tlsext_debug_arg;
    param_1[2].tlsext_ticket_expected = (int)ses;
    uVar4 = iVar3 << 0x16;
    bVar5 = (int)uVar4 < 0;
    ses->ssl_version = iVar2;
    if (bVar5) {
      uVar4 = *(uint *)ses[1].key_arg;
    }
    ses->verify_result = 0;
    if (bVar5) {
      uVar4 = uVar4 | 1;
    }
    if (bVar5) {
      *(uint *)ses[1].key_arg = uVar4;
    }
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0xb5,0x44,"ssl/ssl_sess.c",0x192);
  SSL_SESSION_free(ses);
  return 0;
}

