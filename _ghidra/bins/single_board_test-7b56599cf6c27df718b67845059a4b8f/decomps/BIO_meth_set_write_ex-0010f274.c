
undefined4 BIO_meth_set_write_ex(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 1;
}

