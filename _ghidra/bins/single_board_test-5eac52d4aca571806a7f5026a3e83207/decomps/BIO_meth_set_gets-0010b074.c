
undefined4 BIO_meth_set_gets(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return 1;
}

