
undefined4 BIO_meth_set_write(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 8) = 0x118cd9;
  return 1;
}

