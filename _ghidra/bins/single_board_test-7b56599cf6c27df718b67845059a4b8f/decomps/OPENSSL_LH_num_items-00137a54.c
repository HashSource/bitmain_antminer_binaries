
int OPENSSL_LH_num_items(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 0x24);
  }
  return param_1;
}

