
uint dtls1_ctrl(SSL *param_1,int param_2,ulong param_3,void *param_4)

{
  uint uVar1;
  int *piVar2;
  BIO *bp;
  int iVar3;
  
  if (param_2 == 0x4b) {
    SSL_clear(param_1);
    SSL_ctrl(param_1,0x20,0x2000,(void *)0x0);
    param_1->d1->mtu = 1;
    uVar1 = SSL_accept(param_1);
    if (0 < (int)uVar1) {
      bp = SSL_get_rbio(param_1);
      BIO_ctrl(bp,0x2e,0,param_4);
      uVar1 = 1;
    }
    return uVar1;
  }
  if (param_2 < 0x4c) {
    if (param_2 == 0x49) {
      uVar1 = dtls1_get_timeout(param_1,param_4);
      if (uVar1 != 0) {
        uVar1 = 1;
      }
      return uVar1;
    }
    if (0x49 < param_2) {
      uVar1 = dtls1_handle_timeout();
      return uVar1;
    }
    if (param_2 != 0x11) goto LAB_000764e0;
    iVar3 = dtls1_link_min_mtu();
    if (iVar3 + -0x30 <= (int)param_3) {
      (param_1->d1->w_msg_hdr).msg_len = param_3;
      return param_3;
    }
  }
  else {
    if (param_2 != 0x78) {
      if (param_2 == 0x79) {
        uVar1 = dtls1_link_min_mtu();
        return uVar1;
      }
      if (param_2 == 0x77) {
        iVar3 = **(int **)param_1->psk_server_callback;
        if (param_1->version == iVar3) {
          uVar1 = 1;
        }
        else {
          piVar2 = (int *)DTLS_method();
          if (iVar3 != *piVar2) {
            return 0;
          }
          if (param_1->references << 4 < 0) {
            if (param_1->references << 5 < 0) {
              return 0;
            }
            uVar1 = (uint)(param_1->version == 0xfeff);
          }
          else {
            uVar1 = (uint)(param_1->version == 0xfefd);
          }
        }
        return uVar1;
      }
LAB_000764e0:
      uVar1 = ssl3_ctrl(param_1,param_2,param_3,param_4);
      return uVar1;
    }
    iVar3 = dtls1_link_min_mtu();
    if (iVar3 <= (int)param_3) {
      *(ulong *)&param_1->d1->w_msg_hdr = param_3;
      return 1;
    }
  }
  return 0;
}

