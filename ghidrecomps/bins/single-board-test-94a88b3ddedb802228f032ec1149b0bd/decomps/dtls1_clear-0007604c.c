
void dtls1_clear(SSL *param_1)

{
  uchar uVar1;
  undefined3 uVar2;
  long lVar3;
  int iVar4;
  dtls1_state_st *pdVar5;
  pqueue p_Var6;
  pqueue p_Var7;
  pqueue p_Var8;
  pqueue p_Var9;
  pqueue p_Var10;
  ulong uVar11;
  bool bVar12;
  
  pdVar5 = param_1->d1;
  if (pdVar5 != (dtls1_state_st *)0x0) {
    p_Var10 = (pdVar5->unprocessed_rcds).q;
    p_Var9 = (pdVar5->processed_rcds).q;
    p_Var8 = pdVar5->buffered_messages;
    p_Var7 = pdVar5->sent_messages;
    p_Var6 = (pdVar5->buffered_app_data).q;
    uVar11 = (pdVar5->w_msg_hdr).msg_len;
    uVar1 = (pdVar5->w_msg_hdr).type;
    uVar2 = *(undefined3 *)&(pdVar5->w_msg_hdr).field_0x1;
    dtls1_clear_queues();
    memset(param_1->d1,0,0x2ec);
    if (param_1->server != 0) {
      param_1->d1->cookie_len = 0x100;
    }
    lVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    pdVar5 = param_1->d1;
    bVar12 = lVar3 << 0x13 < 0;
    if (bVar12) {
      (pdVar5->w_msg_hdr).msg_len = uVar11;
    }
    if (bVar12) {
      (pdVar5->w_msg_hdr).type = uVar1;
      *(undefined3 *)&(pdVar5->w_msg_hdr).field_0x1 = uVar2;
    }
    (pdVar5->unprocessed_rcds).q = p_Var10;
    (pdVar5->processed_rcds).q = p_Var9;
    pdVar5->buffered_messages = p_Var8;
    pdVar5->sent_messages = p_Var7;
    (pdVar5->buffered_app_data).q = p_Var6;
  }
  ssl3_clear(param_1);
  if (param_1->references << 0x10 < 0) {
    param_1->version = 0x100;
    param_1->first_packet = 0x100;
    return;
  }
  iVar4 = param_1->method->version;
  if (iVar4 == 0x1ffff) {
    param_1->version = 0xfefd;
  }
  else {
    param_1->version = iVar4;
  }
  return;
}

