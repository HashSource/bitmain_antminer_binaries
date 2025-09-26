
void ssl_cert_set_cert_cb(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x144) = param_2;
  *(undefined4 *)(param_1 + 0x148) = param_3;
  return;
}

