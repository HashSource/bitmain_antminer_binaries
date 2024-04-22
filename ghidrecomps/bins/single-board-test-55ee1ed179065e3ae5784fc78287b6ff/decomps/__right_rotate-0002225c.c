
void __right_rotate(int *param_1,int **param_2)

{
  int *piVar1;
  
  piVar1 = *param_2;
  *param_2 = (int *)piVar1[1];
  if ((int *)piVar1[1] != param_1 + 1) {
    *(int ***)(piVar1[1] + 8) = param_2;
  }
  if (param_1 + 1 != piVar1) {
    piVar1[2] = (int)param_2[2];
  }
  if (param_2[2] == (int *)0x0) {
    *param_1 = (int)piVar1;
  }
  else if ((int **)param_2[2][1] == param_2) {
    param_2[2][1] = (int)piVar1;
  }
  else {
    *param_2[2] = (int)piVar1;
  }
  piVar1[1] = (int)param_2;
  if ((int **)(param_1 + 1) != param_2) {
    param_2[2] = piVar1;
  }
  return;
}

