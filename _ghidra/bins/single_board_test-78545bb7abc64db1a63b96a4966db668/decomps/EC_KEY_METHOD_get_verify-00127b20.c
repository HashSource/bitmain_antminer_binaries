
void EC_KEY_METHOD_get_verify(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x34);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x38);
  }
  return;
}

