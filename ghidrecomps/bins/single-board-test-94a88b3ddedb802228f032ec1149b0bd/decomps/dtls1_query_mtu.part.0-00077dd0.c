
undefined4 dtls1_query_mtu_part_0(SSL *param_1)

{
  BIO *pBVar1;
  ulong uVar2;
  long lVar3;
  dtls1_state_st *pdVar4;
  dtls1_state_st *pdVar5;
  uint uVar6;
  
  pdVar5 = param_1->d1;
  pBVar1 = SSL_get_wbio(param_1);
  uVar2 = BIO_ctrl(pBVar1,0x28,0,(void *)0x0);
  pdVar4 = param_1->d1;
  (pdVar5->w_msg_hdr).msg_len = uVar2;
  uVar6 = (pdVar4->w_msg_hdr).msg_len;
  pBVar1 = SSL_get_wbio(param_1);
  lVar3 = BIO_ctrl(pBVar1,0x31,0,(void *)0x0);
  if (uVar6 < 0x100U - lVar3) {
    pdVar4 = param_1->d1;
    pBVar1 = SSL_get_wbio(param_1);
    lVar3 = BIO_ctrl(pBVar1,0x31,0,(void *)0x0);
    (pdVar4->w_msg_hdr).msg_len = 0x100 - lVar3;
    pBVar1 = SSL_get_wbio(param_1);
    BIO_ctrl(pBVar1,0x2a,(param_1->d1->w_msg_hdr).msg_len,(void *)0x0);
  }
  return 1;
}

