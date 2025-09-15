
undefined4 json_array_append_new(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    if (((param_1 != (int *)0x0) && (*param_1 == 1)) && (param_1 != param_2)) {
      iVar1 = json_array_grow(param_1,1,1);
      if (iVar1 != 0) {
        *(int **)(param_1[4] + param_1[3] * 4) = param_2;
        param_1[3] = param_1[3] + 1;
        return 0;
      }
      json_decref(param_2);
      return 0xffffffff;
    }
    json_decref(param_2);
  }
  return 0xffffffff;
}

