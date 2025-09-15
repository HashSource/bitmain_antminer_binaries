
undefined4 json_array_set_new(int *param_1,uint param_2,int *param_3)

{
  if (param_3 != (int *)0x0) {
    if (((param_1 != (int *)0x0) && (*param_1 == 1)) && (param_1 != param_3)) {
      if (param_2 < (uint)param_1[3]) {
        json_decref(*(undefined4 *)(param_1[4] + param_2 * 4));
        *(int **)(param_1[4] + param_2 * 4) = param_3;
        return 0;
      }
      json_decref(param_3);
      return 0xffffffff;
    }
    json_decref(param_3);
  }
  return 0xffffffff;
}

