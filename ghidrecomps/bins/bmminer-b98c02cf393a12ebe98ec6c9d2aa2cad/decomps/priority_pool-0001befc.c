
int priority_pool(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (0 < total_pools) {
    iVar1 = *pools;
    if (param_1 != *(int *)(iVar1 + 4)) {
      iVar3 = 0;
      piVar2 = pools;
      do {
        iVar3 = iVar3 + 1;
        if (iVar3 == total_pools) goto LAB_0001bf32;
        piVar2 = piVar2 + 1;
        iVar1 = *piVar2;
      } while (*(int *)(iVar1 + 4) != param_1);
    }
    return iVar1;
  }
LAB_0001bf32:
  iVar1 = priority_pool_part_9();
  return iVar1;
}

