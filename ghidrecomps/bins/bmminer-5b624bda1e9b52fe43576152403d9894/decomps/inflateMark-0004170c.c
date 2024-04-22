
int inflateMark(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x1c), piVar1 != (int *)0x0)) {
    if (*piVar1 == 0xf) {
      iVar2 = piVar1[0x10];
    }
    else if (*piVar1 == 0x18) {
      iVar2 = piVar1[0x6f2] - piVar1[0x10];
    }
    else {
      iVar2 = 0;
    }
    return iVar2 + piVar1[0x6f1] * 0x10000;
  }
  return -0x10000;
}

