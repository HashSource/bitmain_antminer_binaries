
void dh_param_encode(int param_1,uchar **param_2)

{
  if (*(int *)(param_1 + 0xc) != DAT_000a53f4) {
    i2d_DHparams(*(DH **)(param_1 + 0x14),param_2);
    return;
  }
  i2d_DHxparams();
  return;
}

