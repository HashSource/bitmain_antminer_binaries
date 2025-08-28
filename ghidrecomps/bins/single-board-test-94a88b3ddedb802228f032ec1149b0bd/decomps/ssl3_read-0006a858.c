
void ssl3_read(SSL *param_1,uchar *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int extraout_r2;
  int iVar4;
  SSL_METHOD *pSVar5;
  int extraout_r3;
  ssl3_state_st *psVar6;
  bool bVar7;
  
  piVar1 = __errno_location();
  psVar6 = param_1->s3;
  *piVar1 = 0;
  if (((psVar6->renegotiate != 0) && ((psVar6->rbuf).left == 0)) && ((psVar6->wbuf).left == 0)) {
    uVar3 = SSL_state(param_1);
    psVar6 = param_1->s3;
    bVar7 = (uVar3 & 0x3000) == 0;
    iVar2 = extraout_r3;
    if (bVar7) {
      iVar2 = 0x3004;
    }
    iVar4 = extraout_r2;
    if (bVar7) {
      param_1->state = iVar2;
      iVar4 = psVar6->num_renegotiations;
      iVar2 = psVar6->total_renegotiations;
    }
    if (bVar7) {
      psVar6->renegotiate = 0;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 1;
    }
    if (bVar7) {
      psVar6->num_renegotiations = iVar4;
    }
    if (bVar7) {
      psVar6->total_renegotiations = iVar2;
    }
  }
  pSVar5 = param_1->method;
  psVar6->in_read_app_data = 1;
  iVar2 = (*pSVar5->ssl_read_bytes)(param_1,0x17,param_2,param_3,0);
  if ((iVar2 == -1) && (param_1->s3->in_read_app_data == 2)) {
    param_1->in_handshake = param_1->in_handshake + 1;
    (*param_1->method->ssl_read_bytes)(param_1,0x17,param_2,param_3,0);
    param_1->in_handshake = param_1->in_handshake + -1;
  }
  else {
    param_1->s3->in_read_app_data = 0;
  }
  return;
}

