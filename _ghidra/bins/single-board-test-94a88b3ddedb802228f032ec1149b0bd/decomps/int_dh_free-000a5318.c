
void int_dh_free(int param_1)

{
  DH_free(*(DH **)(param_1 + 0x14));
  return;
}

