
void dtls1_stop_timer(SSL *param_1)

{
  BIO *bp;
  dtls1_state_st *pdVar1;
  
  pdVar1 = param_1->d1;
  *(undefined *)&(pdVar1->timeout).num_alerts = 0;
  *(undefined *)((int)&(pdVar1->timeout).num_alerts + 1) = 0;
  *(undefined *)((int)&(pdVar1->timeout).num_alerts + 2) = 0;
  *(undefined *)((int)&(pdVar1->timeout).num_alerts + 3) = 0;
  *(undefined *)&(pdVar1->next_timeout).tv_sec = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_sec + 1) = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_sec + 2) = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_sec + 3) = 0;
  *(undefined *)&(pdVar1->next_timeout).tv_usec = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_usec + 1) = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_usec + 2) = 0;
  *(undefined *)((int)&(pdVar1->next_timeout).tv_usec + 3) = 0;
  pdVar1 = param_1->d1;
  *(undefined *)&pdVar1->timeout_duration = 0;
  *(undefined *)((int)&pdVar1->timeout_duration + 1) = 0;
  pdVar1->alert_fragment[0] = '\0';
  pdVar1->alert_fragment[1] = '\0';
  *(undefined *)&pdVar1->alert_fragment_len = 0;
  *(undefined *)((int)&pdVar1->alert_fragment_len + 1) = 0;
  *(undefined *)((int)&pdVar1->alert_fragment_len + 2) = 0;
  *(undefined *)((int)&pdVar1->alert_fragment_len + 3) = 0;
  *(undefined2 *)param_1->d1->handshake_fragment = 1;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&param_1->d1->timeout_duration);
  dtls1_clear_record_buffer(param_1);
  return;
}

