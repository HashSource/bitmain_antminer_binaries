
int ssl3_write(SSL *param_1,void *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  BIO *bp;
  int iVar4;
  ssl3_state_st *psVar5;
  bool bVar6;
  
  iVar2 = param_3;
  piVar1 = __errno_location();
  psVar5 = param_1->s3;
  *piVar1 = 0;
  if (((psVar5->renegotiate != 0) && ((psVar5->rbuf).left == 0)) &&
     (iVar4 = (psVar5->wbuf).left, iVar4 == 0)) {
    uVar3 = SSL_state(param_1);
    psVar5 = param_1->s3;
    bVar6 = (uVar3 & 0x3000) == 0;
    if (bVar6) {
      iVar4 = 0x3004;
    }
    if (bVar6) {
      param_1->state = iVar4;
      iVar2 = psVar5->num_renegotiations;
      iVar4 = psVar5->total_renegotiations;
    }
    if (bVar6) {
      psVar5->renegotiate = 0;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 1;
    }
    if (bVar6) {
      psVar5->num_renegotiations = iVar2;
    }
    if (bVar6) {
      psVar5->total_renegotiations = iVar4;
    }
  }
  if ((psVar5->flags << 0x1d < 0) && (bp = param_1->wbio, bp == param_1->bbio)) {
    if (psVar5->delay_buf_pop_ret == 0) {
      iVar2 = ssl3_write_bytes(param_1,0x17,param_2,param_3);
      if (iVar2 < 1) {
        return iVar2;
      }
      bp = param_1->wbio;
      param_1->s3->delay_buf_pop_ret = iVar2;
    }
    param_1->rwstate = 2;
    iVar2 = BIO_ctrl(bp,0xb,0,(void *)0x0);
    if (0 < iVar2) {
      param_1->rwstate = 1;
      ssl_free_wbio_buffer(param_1);
      psVar5 = param_1->s3;
      iVar2 = psVar5->delay_buf_pop_ret;
      psVar5->delay_buf_pop_ret = 0;
      psVar5->flags = psVar5->flags & 0xfffffffb;
      return iVar2;
    }
  }
  else {
    iVar2 = (*param_1->method->ssl_write_bytes)(param_1,0x17,param_2,param_3);
  }
  return iVar2;
}

