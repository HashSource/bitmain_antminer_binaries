
void EC_KEY_METHOD_get_keygen(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x20);
  }
  return;
}

