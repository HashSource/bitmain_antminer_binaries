
int inflateSyncPoint(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != 0) && (piVar2 = *(int **)(param_1 + 0x1c), piVar2 != (int *)0x0)) {
    if (*piVar2 != 0xd) {
      return 0;
    }
    iVar1 = 1 - piVar2[0xf];
    if (1 < (uint)piVar2[0xf]) {
      iVar1 = 0;
    }
    return iVar1;
  }
  return -2;
}

