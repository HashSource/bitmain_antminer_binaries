
int * X509v3_asid_inherits(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (((int *)*param_1 == (int *)0x0) || (*(int *)*param_1 != 0)) {
      param_1 = (int *)param_1[1];
      if (param_1 != (int *)0x0) {
        return (int *)(uint)(*param_1 == 0);
      }
    }
    else {
      param_1 = (int *)0x1;
    }
  }
  return param_1;
}

