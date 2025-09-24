
undefined4 EVP_MD_meth_set_cleanup(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return 1;
}

