
int select_balanced(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar5;
  int iVar6;
  undefined8 uVar7;
  int *piVar4;
  
  iVar6 = *(int *)(param_1 + 0x9c);
  if (0 < total_pools) {
    piVar5 = pools + total_pools;
    piVar3 = pools;
    do {
      while( true ) {
        piVar4 = piVar3 + 1;
        iVar1 = *piVar3;
        piVar3 = piVar4;
        if (((*(char *)(iVar1 + 0x61) != '\0') || (*(int *)(iVar1 + 100) != 1)) ||
           (uVar7 = pool_unusable_part_4(iVar1), iVar1 = (int)((ulonglong)uVar7 >> 0x20),
           (int)uVar7 != 0)) break;
        iVar2 = *(int *)(iVar1 + 0x9c);
        if (iVar2 < iVar6) {
          iVar6 = iVar2;
          param_1 = iVar1;
        }
        if (piVar4 == piVar5) goto LAB_0001be8a;
      }
    } while (piVar4 != piVar5);
LAB_0001be8a:
    iVar6 = *(int *)(param_1 + 0x9c);
  }
  *(int *)(param_1 + 0x9c) = iVar6 + 1;
  return param_1;
}

