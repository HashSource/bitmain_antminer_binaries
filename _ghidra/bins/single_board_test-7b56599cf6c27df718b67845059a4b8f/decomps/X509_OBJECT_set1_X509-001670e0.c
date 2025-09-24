
undefined4 X509_OBJECT_set1_X509(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = X509_up_ref(param_2);
  if (iVar1 == 0) {
    return 0;
  }
  if (*param_1 == 1) {
    X509_free((X509 *)param_1[1]);
  }
  else if (*param_1 == 2) {
    X509_CRL_free((X509_CRL *)param_1[1]);
  }
  param_1[1] = param_2;
  *param_1 = 1;
  return 1;
}

