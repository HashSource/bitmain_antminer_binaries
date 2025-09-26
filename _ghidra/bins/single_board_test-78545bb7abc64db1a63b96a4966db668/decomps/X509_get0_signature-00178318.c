
void X509_get0_signature(int *param_1,int *param_2,int param_3)

{
  if (param_1 != (int *)0x0) {
    *param_1 = param_3 + 0x50;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = param_3 + 0x48;
  }
  return;
}

