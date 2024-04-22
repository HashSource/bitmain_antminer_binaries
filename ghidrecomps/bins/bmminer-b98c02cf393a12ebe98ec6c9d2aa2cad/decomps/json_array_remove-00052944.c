
undefined4 json_array_remove(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (((param_1 == (int *)0x0) || (*param_1 != 1)) || (uVar2 = param_1[3], uVar2 <= param_2)) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(param_1[4] + param_2 * 4);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 4) != -1)) &&
     (iVar3 = *(int *)(iVar1 + 4) + -1, *(int *)(iVar1 + 4) = iVar3, iVar3 == 0)) {
    json_delete();
    uVar2 = param_1[3];
  }
  uVar2 = uVar2 - 1;
  if (param_2 < uVar2) {
    memmove((void *)(param_1[4] + param_2 * 4),(void *)(param_2 * 4 + 4 + param_1[4]),
            (uVar2 - param_2) * 4);
    param_1[3] = param_1[3] + -1;
    return 0;
  }
  param_1[3] = uVar2;
  return 0;
}

