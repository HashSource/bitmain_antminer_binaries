
undefined4 rsa_pss_cb(int param_1,int *param_2)

{
  if (param_1 != 2) {
    return 1;
  }
  X509_ALGOR_free(*(X509_ALGOR **)(*param_2 + 0x10));
  return 1;
}

