
undefined4 ssl3_renegotiate_check(SSL *param_1)

{
  uint uVar1;
  ssl3_state_st *psVar2;
  
  psVar2 = param_1->s3;
  if (((psVar2->renegotiate != 0) && ((psVar2->rbuf).left == 0)) && ((psVar2->wbuf).left == 0)) {
    uVar1 = SSL_state(param_1);
    if ((uVar1 & 0x3000) == 0) {
      psVar2 = param_1->s3;
      param_1->state = 0x3004;
      psVar2->renegotiate = 0;
      psVar2->num_renegotiations = psVar2->num_renegotiations + 1;
      psVar2->total_renegotiations = psVar2->total_renegotiations + 1;
      return 1;
    }
  }
  return 0;
}

