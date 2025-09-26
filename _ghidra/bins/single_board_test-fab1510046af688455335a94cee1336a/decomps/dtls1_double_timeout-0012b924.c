
void dtls1_double_timeout(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  BIO *bp;
  ushort uVar2;
  int iVar3;
  
  pdVar1 = param_1->d1;
  uVar2 = *(short *)pdVar1->handshake_fragment << 1;
  if (0x3c < uVar2) {
    uVar2 = 0x3c;
  }
  *(ushort *)pdVar1->handshake_fragment = uVar2;
  iVar3._0_2_ = pdVar1->timeout_duration;
  iVar3._2_1_ = pdVar1->alert_fragment[0];
  iVar3._3_1_ = pdVar1->alert_fragment[1];
  if ((iVar3 == 0) && (pdVar1->alert_fragment_len == 0)) {
    pdVar1->handshake_fragment[0] = '\x01';
    pdVar1->handshake_fragment[1] = '\0';
  }
  gettimeofday((timeval *)&pdVar1->timeout_duration,(__timezone_ptr_t)0x0);
  pdVar1 = param_1->d1;
  *(uint *)&pdVar1->timeout_duration =
       *(int *)&pdVar1->timeout_duration + (uint)*(ushort *)pdVar1->handshake_fragment;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&param_1->d1->timeout_duration);
  return;
}

