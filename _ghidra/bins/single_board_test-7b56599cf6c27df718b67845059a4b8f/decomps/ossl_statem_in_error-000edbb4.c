
bool ossl_statem_in_error(int param_1)

{
  return *(int *)(param_1 + 0x2c) == 1;
}

