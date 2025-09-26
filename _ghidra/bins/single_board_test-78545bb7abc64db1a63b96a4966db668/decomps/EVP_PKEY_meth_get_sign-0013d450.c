
void EVP_PKEY_meth_get_sign(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x24);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x28);
  }
  return;
}

