
void X509_REQ_get0_signature(int param_1,undefined4 *param_2,int *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x24);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = param_1 + 0x1c;
  }
  return;
}

