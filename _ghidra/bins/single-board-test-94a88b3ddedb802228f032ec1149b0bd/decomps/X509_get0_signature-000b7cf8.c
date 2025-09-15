
void X509_get0_signature(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(param_3 + 8);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_3 + 4);
  }
  return;
}

