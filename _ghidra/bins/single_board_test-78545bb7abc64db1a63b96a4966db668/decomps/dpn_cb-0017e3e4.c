
undefined4 dpn_cb(int param_1,int *param_2)

{
  if (param_1 != 1) {
    if (param_1 == 3) {
      X509_NAME_free(*(X509_NAME **)(*param_2 + 8));
    }
    return 1;
  }
  *(undefined4 *)(*param_2 + 8) = 0;
  return 1;
}

