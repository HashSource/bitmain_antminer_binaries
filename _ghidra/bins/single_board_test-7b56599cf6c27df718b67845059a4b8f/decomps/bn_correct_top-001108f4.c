
void bn_correct_top(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  if (0 < iVar2) {
    piVar1 = (int *)(*param_1 + iVar2 * 4);
    do {
      piVar1 = piVar1 + -1;
      if (*piVar1 != 0) break;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    param_1[1] = iVar2;
  }
  if (iVar2 == 0) {
    param_1[3] = 0;
  }
  return;
}

