
void SSL_set_post_handshake_auth(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x5f8) = param_2;
  return;
}

