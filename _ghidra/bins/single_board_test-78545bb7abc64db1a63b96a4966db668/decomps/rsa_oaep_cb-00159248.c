
undefined4 rsa_oaep_cb(int param_1,int *param_2)

{
  if (param_1 != 2) {
    return 1;
  }
  X509_ALGOR_free(*(X509_ALGOR **)(*param_2 + 0xc));
  return 1;
}

