
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
  switch(*param_1) {
  case 0:
    iVar3 = piVar1[3] - piVar2[3];
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = (*(code *)PTR_memcmp_00194160)(piVar1[4],piVar2[4],piVar1[3]);
    return iVar3;
  case 1:
    if (*piVar1 == 0) {
      return -1;
    }
    iVar3 = *piVar2;
    break;
  case 2:
    if (piVar1[1] == 0) {
      return -1;
    }
    iVar3 = piVar2[1];
    break;
  case 3:
    return piVar1[2] - piVar2[2];
  default:
    return 0;
  }
  if (iVar3 == 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00012410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*(code *)PTR_LAB_00194368)();
  return iVar3;
}

