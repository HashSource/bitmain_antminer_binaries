
void ossl_statem_set_in_handshake(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;
    return;
  }
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  return;
}

