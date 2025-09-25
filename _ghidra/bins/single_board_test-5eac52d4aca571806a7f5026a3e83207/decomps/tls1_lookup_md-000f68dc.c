
undefined4 tls1_lookup_md(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = ssl_md(*(undefined4 *)(param_1 + 0xc));
    if (iVar1 == 0) {
      return 0;
    }
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar1;
    return 1;
  }
  return 1;
}

