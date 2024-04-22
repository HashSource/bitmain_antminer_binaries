
int dtls1_heartbeat(SSL *param_1)

{
  uint uVar1;
  undefined *buf;
  int iVar2;
  
  if (((uint)param_1->srtp_profile & 3) == 1) {
    if (param_1->tlsext_heartbeat == 0) {
      uVar1 = SSL_state(param_1);
      if (((uVar1 & 0x3000) == 0) && (param_1->in_handshake == 0)) {
        buf = (undefined *)CRYPTO_malloc(0x25,DAT_0007951c,0x5eb);
        *buf = 1;
        buf[1] = 0;
        buf[2] = 0x12;
        buf[3] = (char)(param_1->tlsext_hb_pending >> 8);
        buf[4] = (char)param_1->tlsext_hb_pending;
        iVar2 = RAND_pseudo_bytes(buf + 5,0x10);
        if ((iVar2 < 0) || (iVar2 = RAND_pseudo_bytes(buf + 0x15,0x10), iVar2 < 0)) {
          iVar2 = -1;
        }
        else {
          iVar2 = dtls1_write_bytes(param_1,0x18,buf,0x25);
          if (-1 < iVar2) {
            if (param_1->msg_callback != (_func_3292 *)0x0) {
              (*param_1->msg_callback)
                        (1,param_1->version,0x18,buf,0x25,param_1,param_1->msg_callback_arg);
            }
            dtls1_start_timer(param_1);
            param_1->tlsext_heartbeat = 1;
          }
        }
        CRYPTO_free(buf);
      }
      else {
        ERR_put_error(0x14,0x131,0xf4,DAT_0007951c,0x5d7);
        iVar2 = -1;
      }
    }
    else {
      ERR_put_error(0x14,0x131,0x16e,DAT_0007951c,0x5d1);
      iVar2 = -1;
    }
  }
  else {
    ERR_put_error(0x14,0x131,0x16d,DAT_0007951c,0x5cb);
    iVar2 = -1;
  }
  return iVar2;
}

