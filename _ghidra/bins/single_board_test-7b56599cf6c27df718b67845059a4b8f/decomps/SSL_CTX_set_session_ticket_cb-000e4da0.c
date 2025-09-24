
undefined4
SSL_CTX_set_session_ticket_cb(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x234) = param_2;
  *(undefined4 *)(param_1 + 0x238) = param_3;
  *(undefined4 *)(param_1 + 0x23c) = param_4;
  return 1;
}

