
undefined4 json_array_set_new(int *param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 == (int *)0x0) {
    return 0xffffffff;
  }
  if (((param_1 != (int *)0x0) && (*param_1 == 1 && param_3 != param_1)) &&
     (param_2 < (uint)param_1[3])) {
    iVar3 = param_1[4];
    iVar1 = *(int *)(iVar3 + param_2 * 4);
    if (((iVar1 != 0) && (*(int *)(iVar1 + 4) != -1)) &&
       (iVar2 = *(int *)(iVar1 + 4) + -1, *(int *)(iVar1 + 4) = iVar2, iVar2 == 0)) {
      json_delete();
      *(int **)(param_1[4] + param_2 * 4) = param_3;
      return 0;
    }
    *(int **)(iVar3 + param_2 * 4) = param_3;
    return 0;
  }
  if ((param_3[1] != -1) && (iVar1 = param_3[1] + -1, param_3[1] = iVar1, iVar1 == 0)) {
    json_delete(param_3);
  }
  return 0xffffffff;
}

