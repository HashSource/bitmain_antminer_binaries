
void remove_pool(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar4;
  int iVar5;
  int *piVar3;
  
  iVar5 = total_pools + -1;
  if (0 < total_pools) {
    piVar1 = pools + total_pools;
    piVar2 = pools;
    do {
      piVar3 = piVar2 + 1;
      iVar4 = *(int *)(*piVar2 + 4);
      if (param_1[1] < iVar4) {
        *(int *)(*piVar2 + 4) = iVar4 + -1;
      }
      piVar2 = piVar3;
    } while (piVar3 != piVar1);
  }
  piVar2 = pools;
  if (*param_1 < iVar5) {
    piVar1 = (int *)pools[iVar5];
    *piVar1 = *param_1;
    piVar2[*param_1] = (int)piVar1;
  }
  *param_1 = total_pools;
  *(undefined *)((int)param_1 + 0x69) = 1;
  total_pools = iVar5;
  return;
}

