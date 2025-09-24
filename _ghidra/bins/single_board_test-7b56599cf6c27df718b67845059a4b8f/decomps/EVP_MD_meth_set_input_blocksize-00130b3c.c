
undefined4 EVP_MD_meth_set_input_blocksize(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return 1;
}

