
void X509_CRL_get0_signature(int param_1,int *param_2,int *param_3)

{
  if (param_2 != (int *)0x0) {
    *param_2 = param_1 + 0x34;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = param_1 + 0x2c;
  }
  return;
}

