
void EVP_PKEY_meth_get_param_check(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x7c);
  }
  return;
}

