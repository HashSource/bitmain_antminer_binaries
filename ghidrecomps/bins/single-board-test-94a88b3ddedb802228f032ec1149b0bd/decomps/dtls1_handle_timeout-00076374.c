
undefined4 dtls1_handle_timeout(SSL *param_1)

{
  int iVar1;
  undefined4 uVar2;
  dtls1_state_st *pdVar3;
  BIO *pBVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  int local_18;
  int local_14;
  
  iVar1 = dtls1_get_timeout(param_1,&local_18);
  if (((iVar1 == 0) || (0 < local_18)) || (0 < local_14)) {
    uVar2 = 0;
  }
  else {
    pdVar3 = param_1->d1;
    uVar8 = *(short *)pdVar3->handshake_fragment << 1;
    if (0x3c < uVar8) {
      uVar8 = 0x3c;
    }
    *(ushort *)pdVar3->handshake_fragment = uVar8;
    iVar1._0_2_ = pdVar3->timeout_duration;
    iVar1._2_1_ = pdVar3->alert_fragment[0];
    iVar1._3_1_ = pdVar3->alert_fragment[1];
    if ((iVar1 == 0) && (pdVar3->alert_fragment_len == 0)) {
      pdVar3->handshake_fragment[0] = '\x01';
      pdVar3->handshake_fragment[1] = '\0';
    }
    gettimeofday((timeval *)&pdVar3->timeout_duration,(__timezone_ptr_t)0x0);
    pdVar3 = param_1->d1;
    *(uint *)&pdVar3->timeout_duration =
         *(int *)&pdVar3->timeout_duration + (uint)*(ushort *)pdVar3->handshake_fragment;
    pBVar4 = SSL_get_rbio(param_1);
    BIO_ctrl(pBVar4,0x2d,0,&param_1->d1->timeout_duration);
    pdVar3 = param_1->d1;
    uVar5 = (pdVar3->next_timeout).tv_usec + 1;
    (pdVar3->next_timeout).tv_usec = uVar5;
    if (2 < uVar5) {
      uVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((uVar5 & 0x1000) == 0) {
        pBVar4 = SSL_get_wbio(param_1);
        uVar5 = BIO_ctrl(pBVar4,0x2f,0,(void *)0x0);
        pdVar3 = param_1->d1;
        uVar7 = (pdVar3->next_timeout).tv_usec;
        if (uVar5 < (pdVar3->w_msg_hdr).msg_len) {
          (pdVar3->w_msg_hdr).msg_len = uVar5;
        }
      }
      else {
        pdVar3 = param_1->d1;
        uVar7 = (pdVar3->next_timeout).tv_usec;
      }
      if (0xc < uVar7) {
        ERR_put_error(0x14,0x13c,0x138,"d1_lib.c",0x1e0);
        return 0xffffffff;
      }
    }
    uVar5 = (pdVar3->timeout).num_alerts + 1;
    if (2 < uVar5) {
      uVar5 = 1;
    }
    (pdVar3->timeout).num_alerts = uVar5;
    if (param_1->tlsext_heartbeat == 0) {
      iVar6._0_2_ = pdVar3->timeout_duration;
      iVar6._2_1_ = pdVar3->alert_fragment[0];
      iVar6._3_1_ = pdVar3->alert_fragment[1];
      if ((iVar6 == 0) && (pdVar3->alert_fragment_len == 0)) {
        pdVar3->handshake_fragment[0] = '\x01';
        pdVar3->handshake_fragment[1] = '\0';
      }
      gettimeofday((timeval *)&pdVar3->timeout_duration,(__timezone_ptr_t)0x0);
      pdVar3 = param_1->d1;
      *(uint *)&pdVar3->timeout_duration =
           *(int *)&pdVar3->timeout_duration + (uint)*(ushort *)pdVar3->handshake_fragment;
      pBVar4 = SSL_get_rbio(param_1);
      BIO_ctrl(pBVar4,0x2d,0,&param_1->d1->timeout_duration);
      uVar2 = dtls1_retransmit_buffered_messages(param_1);
    }
    else {
      param_1->tlsext_heartbeat = 0;
      uVar2 = dtls1_heartbeat(param_1);
    }
  }
  return uVar2;
}

