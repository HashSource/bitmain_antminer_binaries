
undefined4 json_array_append_new(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    return 0xffffffff;
  }
  if (((param_1 != (int *)0x0) && (*param_1 == 1 && param_2 != param_1)) &&
     (iVar1 = json_array_grow(param_1,1), iVar1 != 0)) {
    iVar1 = param_1[3];
    *(int **)(param_1[4] + iVar1 * 4) = param_2;
    param_1[3] = iVar1 + 1;
    return 0;
  }
  if ((param_2[1] != -1) && (iVar1 = param_2[1] + -1, param_2[1] = iVar1, iVar1 == 0)) {
    json_delete(param_2);
  }
  return 0xffffffff;
}

