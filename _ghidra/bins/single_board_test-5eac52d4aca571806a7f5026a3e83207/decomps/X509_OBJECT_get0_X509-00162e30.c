
int * X509_OBJECT_get0_X509(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 == 1) {
      return (int *)param_1[1];
    }
    param_1 = (int *)0x0;
  }
  return param_1;
}

