
int dtls1_write_app_data_bytes(SSL *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    iVar2 = (*param_1->handshake_func)(param_1);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x10c,0xe5,DAT_00077ab8,0x594);
      return -1;
    }
  }
  if (param_4 < 0x4001) {
    param_1->rwstate = 1;
    if ((param_1->s3->wbuf).left != 0) {
      OpenSSLDie(DAT_00077ab8,0x5e1,DAT_00077abc);
      iVar2 = ssl3_write_pending(param_1,param_2,param_3,param_4);
      return iVar2;
    }
    if (((param_1->s3->alert_dispatch == 0) ||
        (iVar2 = (*param_1->method->ssl_dispatch_alert)(param_1), 0 < iVar2)) &&
       (iVar2 = param_4, param_4 != 0)) {
      iVar2 = do_dtls1_write_part_2(param_1,param_2,param_3,param_4,0);
    }
  }
  else {
    ERR_put_error(0x14,0x10c,0x14e,DAT_00077ab8,0x59a);
    iVar2 = -1;
  }
  return iVar2;
}

