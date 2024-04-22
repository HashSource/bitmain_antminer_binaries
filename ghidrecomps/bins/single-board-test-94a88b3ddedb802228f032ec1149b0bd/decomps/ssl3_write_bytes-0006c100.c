
uint ssl3_write_bytes(SSL *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  ssl3_state_st *psVar2;
  ulong uVar3;
  ssl3_state_st *psVar4;
  uint uVar5;
  bool bVar6;
  
  psVar4 = param_1->s3;
  uVar1 = psVar4->wnum;
  param_1->rwstate = 1;
  psVar2 = psVar4;
  if ((int)uVar1 < 0) {
    OpenSSLDie(DAT_0006c294,0x287,DAT_0006c298);
    psVar2 = param_1->s3;
  }
  uVar5 = psVar2->wnum;
  psVar2->wnum = 0;
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    uVar1 = (*param_1->handshake_func)(param_1);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (uVar1 == 0) {
      ERR_put_error(0x14,0x9e,0xe5,DAT_0006c294,0x290);
      return 0xffffffff;
    }
  }
  if ((int)param_4 < (int)uVar5) {
    ERR_put_error(0x14,0x9e,0x10f,DAT_0006c294,0x29f);
    return 0xffffffff;
  }
  if ((psVar4->wbuf).left != 0) {
    uVar1 = ssl3_write_pending(param_1,param_2,param_3 + uVar5,param_1->s3->wpend_tot);
    if ((int)uVar1 < 1) {
      param_1->s3->wnum = uVar5;
      return uVar1;
    }
    uVar5 = uVar5 + uVar1;
  }
  if (uVar5 == param_4) {
    if (-1 < (int)(param_1->options << 0x1b)) {
      return uVar5;
    }
    if (*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c < 0) {
      return uVar5;
    }
    ssl3_release_write_buffer(param_1);
    return uVar5;
  }
  param_4 = param_4 - uVar5;
  if (param_2 == 0x17) {
    do {
      uVar1 = param_1->client_version;
      if (param_4 < (uint)param_1->client_version) {
        uVar1 = param_4;
      }
      uVar1 = do_ssl3_write(param_1,0x17,param_3 + uVar5,uVar1,0);
      if ((int)uVar1 < 1) {
LAB_0006c18a:
        param_1->s3->wnum = uVar5;
        return uVar1;
      }
      bVar6 = param_4 == uVar1;
      param_4 = param_4 - uVar1;
      if (bVar6) goto LAB_0006c198;
      if ((int)(param_1->options << 0x1f) < 0) goto LAB_0006c260;
      uVar5 = uVar5 + uVar1;
    } while( true );
  }
  while( true ) {
    uVar1 = param_1->client_version;
    if (param_4 < (uint)param_1->client_version) {
      uVar1 = param_4;
    }
    uVar1 = do_ssl3_write(param_1,param_2,param_3 + uVar5,uVar1,0);
    if ((int)uVar1 < 1) goto LAB_0006c18a;
    bVar6 = param_4 == uVar1;
    param_4 = param_4 - uVar1;
    if (bVar6) break;
    uVar5 = uVar5 + uVar1;
  }
LAB_0006c198:
  uVar3 = param_1->options;
  param_1->s3->empty_fragment_done = 0;
  if (((int)(uVar3 << 0x1b) < 0) && (-1 < *(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c)) {
    ssl3_release_write_buffer(param_1);
  }
LAB_0006c1b2:
  return uVar1 + uVar5;
LAB_0006c260:
  param_1->s3->empty_fragment_done = 0;
  goto LAB_0006c1b2;
}

