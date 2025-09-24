
void DTLS_set_timer_cb(int param_1,undefined4 param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 0x80) + 0x194) = param_2;
  return;
}

