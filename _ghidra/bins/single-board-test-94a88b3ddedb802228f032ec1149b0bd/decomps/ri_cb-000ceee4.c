
undefined4 ri_cb(int param_1,int *param_2)

{
  if (param_1 != 3) {
    return 1;
  }
  X509_free(*(X509 **)(*param_2 + 0x10));
  return 1;
}

