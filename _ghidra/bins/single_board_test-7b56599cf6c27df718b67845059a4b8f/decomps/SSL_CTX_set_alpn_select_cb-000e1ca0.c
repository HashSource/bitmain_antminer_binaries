
void SSL_CTX_set_alpn_select_cb(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x170) = param_2;
  *(undefined4 *)(param_1 + 0x174) = param_3;
  return;
}

