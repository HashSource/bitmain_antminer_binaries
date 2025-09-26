
void RSA_get0_factors(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x1c);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x20);
  }
  return;
}

