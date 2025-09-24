
void SSL_CTX_set_client_hello_cb(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x128) = param_2;
  *(undefined4 *)(param_1 + 300) = param_3;
  return;
}

