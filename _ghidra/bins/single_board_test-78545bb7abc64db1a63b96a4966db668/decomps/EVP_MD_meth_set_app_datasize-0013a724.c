
undefined4 EVP_MD_meth_set_app_datasize(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x28) = param_2;
  return 1;
}

