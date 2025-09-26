
void EC_pre_comp_free(int param_1)

{
  if (*(int *)(param_1 + 0x60) == 5) {
    EC_ec_pre_comp_free(*(undefined4 *)(param_1 + 100));
  }
  *(undefined4 *)(param_1 + 100) = 0;
  return;
}

