
undefined4 dtls1_check_timeout_num(SSL *param_1)

{
  BIO *bp;
  dtls1_state_st *pdVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_1->d1->next_timeout).tv_usec + 1;
  (param_1->d1->next_timeout).tv_usec = uVar2;
  if (2 < uVar2) {
    uVar2 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar2 & 0x1000) == 0) {
      bp = SSL_get_wbio(param_1);
      uVar2 = BIO_ctrl(bp,0x2f,0,(void *)0x0);
      pdVar1 = param_1->d1;
      uVar3 = (pdVar1->next_timeout).tv_usec;
      if (uVar2 < (pdVar1->w_msg_hdr).msg_len) {
        (pdVar1->w_msg_hdr).msg_len = uVar2;
      }
    }
    else {
      uVar3 = (param_1->d1->next_timeout).tv_usec;
    }
    if (0xc < uVar3) {
      ERR_put_error(0x14,0x13c,0x138,DAT_00076370,0x1e0);
      return 0xffffffff;
    }
  }
  return 0;
}

