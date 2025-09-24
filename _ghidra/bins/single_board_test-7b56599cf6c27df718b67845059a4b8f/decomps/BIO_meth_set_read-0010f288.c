
undefined4 BIO_meth_set_read(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0x10f121;
  return 1;
}

