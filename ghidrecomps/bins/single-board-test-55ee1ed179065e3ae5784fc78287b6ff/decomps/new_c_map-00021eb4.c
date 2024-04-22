
int * new_c_map(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)malloc(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    iVar2 = new_c_rb(param_1,param_2,param_3);
    *piVar1 = iVar2;
    if (*piVar1 == 0) {
      piVar1 = (int *)0x0;
    }
  }
  return piVar1;
}

