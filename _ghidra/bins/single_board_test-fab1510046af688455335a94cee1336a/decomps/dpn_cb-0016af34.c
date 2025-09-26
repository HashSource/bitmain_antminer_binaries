
undefined4 dpn_cb(int param_1,int *param_2)

{
  X509_NAME *a;
  
  if (param_1 == 1) {
    *(undefined4 *)(*param_2 + 8) = 0;
    return 1;
  }
  if ((param_1 == 3) && (a = *(X509_NAME **)(*param_2 + 8), a != (X509_NAME *)0x0)) {
    X509_NAME_free(a);
    return 1;
  }
  return 1;
}

