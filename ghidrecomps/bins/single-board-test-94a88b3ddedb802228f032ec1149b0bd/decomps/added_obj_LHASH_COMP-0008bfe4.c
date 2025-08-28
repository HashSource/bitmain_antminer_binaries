
int added_obj_LHASH_COMP(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1 - *param_2;
  if (iVar3 != 0) {
    return iVar3;
  }
  piVar1 = (int *)param_1[1];
  piVar2 = (int *)param_2[1];
  iVar3 = 0;
  switch(*param_1) {
  case 0:
    iVar3 = piVar1[3] - piVar2[3];
    if (iVar3 == 0) {
      iVar3 = memcmp((void *)piVar1[4],(void *)piVar2[4],piVar1[3]);
      return iVar3;
    }
    break;
  case 1:
    if (*piVar1 == 0) {
      return -1;
    }
    iVar3 = *piVar2;
    goto joined_r0x0008c034;
  case 2:
    if (piVar1[1] == 0) {
      return -1;
    }
    iVar3 = piVar2[1];
joined_r0x0008c034:
    if (iVar3 != 0) {
      iVar3 = (*(code *)(undefined *)0x0)();
      return iVar3;
    }
    iVar3 = 1;
    break;
  case 3:
    iVar3 = piVar1[2] - piVar2[2];
  }
  return iVar3;
}

