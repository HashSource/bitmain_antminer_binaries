
void SSL_set_allow_early_data_cb(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0xf80) = param_2;
  *(undefined4 *)(param_1 + 0xf84) = param_3;
  return;
}

