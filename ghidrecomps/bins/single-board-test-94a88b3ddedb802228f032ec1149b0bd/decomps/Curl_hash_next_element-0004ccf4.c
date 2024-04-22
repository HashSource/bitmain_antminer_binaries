
int Curl_hash_next_element(int **param_1)

{
  int iVar1;
  int **ppiVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  if (param_1[2] != (int *)0x0) {
    piVar4 = (int *)param_1[2][2];
    param_1[2] = piVar4;
    if (piVar4 != (int *)0x0) goto LAB_0004cd02;
  }
  piVar3 = param_1[1];
  piVar5 = (int *)(*param_1)[4];
  if ((int)piVar5 <= (int)piVar3) {
    return 0;
  }
  iVar1 = **param_1;
  ppiVar2 = (int **)(iVar1 + (int)piVar3 * 4);
  piVar4 = **(int ***)(iVar1 + (int)piVar3 * 4);
  while (piVar4 == (int *)0x0) {
    piVar3 = (int *)((int)piVar3 + 1);
    if (piVar3 == piVar5) {
      return 0;
    }
    ppiVar2 = ppiVar2 + 1;
    piVar4 = (int *)**ppiVar2;
  }
  param_1[2] = piVar4;
  param_1[1] = (int *)((int)piVar3 + 1);
LAB_0004cd02:
  return *piVar4;
}

