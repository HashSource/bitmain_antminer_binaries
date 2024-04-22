
undefined4 ssl_cert_set_current(int **param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int **)0x0) {
    return 0;
  }
  if (param_2 == 1) {
    iVar1 = 0;
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    iVar1 = ((int)*param_1 - (int)(param_1 + 0xf) >> 2) * -0x49249249 + 1;
    if (7 < iVar1) {
      return 0;
    }
  }
  while( true ) {
    iVar2 = iVar1 + 1;
    if ((param_1[iVar1 * 7 + 0xf] != (int *)0x0) && (param_1[iVar1 * 7 + 0x10] != (int *)0x0))
    break;
    iVar1 = iVar2;
    if (iVar2 == 8) {
      return 0;
    }
  }
  *param_1 = (int *)(param_1 + iVar1 * 7 + 0xf);
  return 1;
}

