
void dtls1_set_handshake_header(int param_1,undefined param_2,int param_3)

{
  dtls1_set_message_header
            (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 4),param_2,param_3,0,param_3);
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(int *)(param_1 + 0x44) = param_3 + 0xc;
  dtls1_buffer_message(param_1,0);
  return;
}

