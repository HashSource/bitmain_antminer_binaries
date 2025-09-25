
void ossl_statem_check_finish_init(int param_1,int param_2)

{
  if (param_2 == -1) {
    if (1 < *(int *)(param_1 + 0x40) - 0x2eU) {
      return;
    }
LAB_000e99e0:
    ossl_statem_set_in_init(param_1,1);
    if (*(int *)(param_1 + 0x68) != 3) {
      return;
    }
    *(undefined4 *)(param_1 + 0x68) = 7;
    return;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (param_2 != 0) {
      if (1 < *(int *)(param_1 + 0x40) - 0x2eU) {
        return;
      }
      if (*(int *)(param_1 + 0x68) == 4) {
        return;
      }
      goto LAB_000e99e0;
    }
  }
  else if (*(int *)(param_1 + 0x68) != 0xc) {
    return;
  }
  if (*(int *)(param_1 + 0x40) != 0x2e) {
    return;
  }
  ossl_statem_set_in_init(param_1,1);
  return;
}

