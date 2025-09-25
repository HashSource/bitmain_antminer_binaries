
void ossl_statem_set_renegotiate(int param_1)

{
  *(undefined4 *)(param_1 + 0x48) = 1;
  *(undefined4 *)(param_1 + 0x44) = 0x13;
  return;
}

