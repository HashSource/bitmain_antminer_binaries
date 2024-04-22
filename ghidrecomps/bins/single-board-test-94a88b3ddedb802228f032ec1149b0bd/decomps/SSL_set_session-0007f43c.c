
int SSL_set_session(SSL *to,SSL_SESSION *session)

{
  SSL_METHOD *method;
  int iVar1;
  int iVar2;
  SSL_SESSION *pSVar3;
  
  if (session == (SSL_SESSION *)0x0) {
    pSVar3 = to->session;
    if (pSVar3 != (SSL_SESSION *)0x0) {
      iVar1 = CRYPTO_add_lock((int *)(pSVar3->krb5_client_princ + 0x14),-1,0xe,DAT_0007f528,0x352);
      if (iVar1 < 1) {
        SSL_SESSION_free_part_0(pSVar3);
      }
      to->session = (SSL_SESSION *)0x0;
    }
    if (to->method == *(SSL_METHOD **)to->psk_server_callback) {
      iVar1 = 1;
    }
    else {
      iVar1 = SSL_set_ssl_method(to,*(SSL_METHOD **)to->psk_server_callback);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
  }
  else {
    method = (SSL_METHOD *)
             (**(code **)(*(int *)to->psk_server_callback + 0x5c))(session->ssl_version);
    if ((method == (SSL_METHOD *)0x0) &&
       (method = (*to->method->get_ssl_method)(session->ssl_version), method == (ssl_method_st *)0x0
       )) {
      ERR_put_error(0x14,0xc3,0xf0,DAT_0007f528,0x390);
      iVar1 = 0;
    }
    else if ((to->method == method) || (iVar1 = SSL_set_ssl_method(to,method), iVar1 != 0)) {
      CRYPTO_add_lock((int *)(session->krb5_client_princ + 0x14),1,0xe,DAT_0007f528,0x3a4);
      pSVar3 = to->session;
      if ((pSVar3 != (SSL_SESSION *)0x0) &&
         (iVar1 = CRYPTO_add_lock((int *)(pSVar3->krb5_client_princ + 0x14),-1,0xe,DAT_0007f528,
                                  0x352), iVar1 < 1)) {
        SSL_SESSION_free_part_0(pSVar3);
      }
      iVar2 = *(int *)(session->krb5_client_princ + 0x10);
      iVar1 = 1;
      to->session = session;
      to->debug = iVar2;
    }
  }
  return iVar1;
}

