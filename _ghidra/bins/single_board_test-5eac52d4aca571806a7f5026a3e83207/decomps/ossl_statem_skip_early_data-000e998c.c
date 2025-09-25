
undefined4 ossl_statem_skip_early_data(int param_1)

{
  if (*(int *)(param_1 + 0x5ac) == 1) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x40) == 0x2e) {
      if (*(int *)(param_1 + 0x44c) == 2) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

