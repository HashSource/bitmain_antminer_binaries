
void dtls1_double_timeout(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  BIO *bp;
  undefined2 uVar2;
  int iVar4;
  uint uVar3;
  
  pdVar1 = param_1->d1;
  uVar3 = (*(ushort *)pdVar1->handshake_fragment & 0x7fff) * 2;
  uVar2 = (undefined2)uVar3;
  if (0x3c < uVar3) {
    uVar2 = 0x3c;
  }
  *(undefined2 *)pdVar1->handshake_fragment = uVar2;
  iVar4._0_2_ = pdVar1->timeout_duration;
  iVar4._2_1_ = pdVar1->alert_fragment[0];
  iVar4._3_1_ = pdVar1->alert_fragment[1];
  if ((iVar4 == 0) && (pdVar1->alert_fragment_len == 0)) {
    *(undefined2 *)pdVar1->handshake_fragment = 1;
  }
  gettimeofday((timeval *)&pdVar1->timeout_duration,(__timezone_ptr_t)0x0);
  pdVar1 = param_1->d1;
  *(uint *)&pdVar1->timeout_duration =
       *(int *)&pdVar1->timeout_duration + (uint)*(ushort *)pdVar1->handshake_fragment;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&param_1->d1->timeout_duration);
  return;
}

