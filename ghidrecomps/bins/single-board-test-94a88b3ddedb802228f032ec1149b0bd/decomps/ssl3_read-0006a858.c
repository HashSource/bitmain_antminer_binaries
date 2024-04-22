
void ssl3_read(SSL *param_1,uchar *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  SSL_METHOD *pSVar4;
  int iVar5;
  ssl3_state_st *psVar6;
  bool bVar7;
  
  iVar2 = param_3;
  piVar1 = __errno_location();
  psVar6 = param_1->s3;
  *piVar1 = 0;
  if (((psVar6->renegotiate != 0) && ((psVar6->rbuf).left == 0)) &&
     (iVar5 = (psVar6->wbuf).left, iVar5 == 0)) {
    uVar3 = SSL_state(param_1);
    psVar6 = param_1->s3;
    bVar7 = (uVar3 & 0x3000) == 0;
    if (bVar7) {
      iVar5 = 0x3004;
    }
    if (bVar7) {
      param_1->state = iVar5;
      iVar2 = psVar6->num_renegotiations;
      iVar5 = psVar6->total_renegotiations;
    }
    if (bVar7) {
      psVar6->renegotiate = 0;
      iVar2 = iVar2 + 1;
      iVar5 = iVar5 + 1;
    }
    if (bVar7) {
      psVar6->num_renegotiations = iVar2;
    }
    if (bVar7) {
      psVar6->total_renegotiations = iVar5;
    }
  }
  pSVar4 = param_1->method;
  psVar6->in_read_app_data = 1;
  iVar2 = (*pSVar4->ssl_read_bytes)(param_1,0x17,param_2,param_3,0);
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

