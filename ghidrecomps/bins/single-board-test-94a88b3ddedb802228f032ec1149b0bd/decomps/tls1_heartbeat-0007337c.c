
int tls1_heartbeat(SSL *param_1)

{
  uint uVar1;
  undefined *buf;
  int iVar2;
  int iVar3;
  
  if (((uint)param_1->srtp_profile & 3) != 1) {
    ERR_put_error(0x14,0x13b,0x16d,DAT_00073498,0xf43);
    return -1;
  }
  if (param_1->tlsext_heartbeat != 0) {
    ERR_put_error(0x14,0x13b,0x16e,DAT_00073498,0xf49);
    return -1;
  }
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) != 0) || (param_1->in_handshake != 0)) {
    ERR_put_error(0x14,0x13b,0xf4,DAT_00073498,0xf4f);
    return -1;
  }
  buf = (undefined *)CRYPTO_malloc(0x25,DAT_00073498,0xf63);
  *buf = 1;
  buf[1] = 0;
  buf[2] = 0x12;
  buf[3] = (char)(param_1->tlsext_hb_pending >> 8);
  buf[4] = (char)param_1->tlsext_hb_pending;
  iVar2 = RAND_pseudo_bytes(buf + 5,0x10);
  if (iVar2 < 0) {
    iVar2 = 0xf6d;
  }
  else {
    iVar2 = RAND_pseudo_bytes(buf + 0x15,0x10);
    if (-1 < iVar2) {
      iVar3 = ssl3_write_bytes(param_1,0x18,buf,0x25);
      if (-1 < iVar3) {
        if (param_1->msg_callback != (_func_3292 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,0x18,buf,0x25,param_1,param_1->msg_callback_arg);
        }
        param_1->tlsext_heartbeat = 1;
      }
      goto LAB_0007341e;
    }
    iVar2 = 0xf73;
  }
  iVar3 = -1;
  ERR_put_error(0x14,0x13b,0x44,DAT_00073498,iVar2);
LAB_0007341e:
  CRYPTO_free(buf);
  return iVar3;
}

