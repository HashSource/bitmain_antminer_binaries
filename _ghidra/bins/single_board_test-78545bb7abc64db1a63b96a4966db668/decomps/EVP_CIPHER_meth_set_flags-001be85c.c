
undefined4 EVP_CIPHER_meth_set_flags(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return 1;
}

