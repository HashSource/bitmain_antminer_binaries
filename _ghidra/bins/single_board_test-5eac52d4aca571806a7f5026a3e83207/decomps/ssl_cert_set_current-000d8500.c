
undefined4 ssl_cert_set_current(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_2 == 1) {
    iVar1 = 0;
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    iVar1 = (*param_1 - (int)(param_1 + 5) >> 2) * -0x33333333 + 1;
    if (8 < iVar1) {
      return 0;
    }
  }
  piVar2 = param_1 + iVar1 * 5 + 5;
  while ((*piVar2 == 0 || (piVar2[1] == 0))) {
    piVar2 = piVar2 + 5;
    if (param_1 + 0x32 == piVar2) {
      return 0;
    }
  }
  *param_1 = (int)piVar2;
  return 1;
}

