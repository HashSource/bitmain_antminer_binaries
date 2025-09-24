
undefined4 EVP_CIPHER_meth_set_cleanup(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return 1;
}

