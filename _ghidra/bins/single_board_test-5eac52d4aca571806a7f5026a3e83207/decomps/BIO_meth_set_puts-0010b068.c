
undefined4 BIO_meth_set_puts(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return 1;
}

