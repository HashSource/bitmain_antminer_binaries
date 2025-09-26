
undefined4 X509_VERIFY_PARAM_set_inh_flags(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return 1;
}

