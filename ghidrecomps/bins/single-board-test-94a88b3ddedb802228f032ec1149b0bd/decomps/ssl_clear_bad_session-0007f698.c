
undefined4 ssl_clear_bad_session(SSL *param_1)

{
  uint uVar1;
  int iVar2;
  SSL_SESSION *pSVar3;
  
  if ((((param_1->session != (SSL_SESSION *)0x0) && (-1 < param_1->shutdown << 0x1f)) &&
      (uVar1 = SSL_state(param_1), (uVar1 & 0x3000) == 0)) &&
     (iVar2 = SSL_state(param_1), -1 < iVar2 << 0x11)) {
    pSVar3 = param_1->session;
    if ((pSVar3 != (SSL_SESSION *)0x0) && (pSVar3->session_id_length != 0)) {
      remove_session_lock_part_1(param_1->psk_server_callback,pSVar3,1);
      return 1;
    }
    return 1;
  }
  return 0;
}

