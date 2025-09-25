
undefined4 EVP_CIPHER_meth_set_init(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return 1;
}

