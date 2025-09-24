
undefined4 OSSL_STORE_LOADER_set_error(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return 1;
}

