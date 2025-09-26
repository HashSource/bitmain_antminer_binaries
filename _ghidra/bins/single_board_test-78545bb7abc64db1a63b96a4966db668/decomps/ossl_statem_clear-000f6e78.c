
void ossl_statem_clear(int param_1)

{
  *(undefined4 *)(param_1 + 0x48) = 1;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  return;
}

