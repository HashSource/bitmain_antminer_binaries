
undefined4 json_array_insert_new(int *param_1,uint param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 != (int *)0x0) {
    if (((param_1 != (int *)0x0) && (*param_1 == 1)) && (param_1 != param_3)) {
      if ((uint)param_1[3] < param_2) {
        json_decref(param_3);
        return 0xffffffff;
      }
      iVar1 = json_array_grow(param_1,1,0);
      if (iVar1 != 0) {
        if (param_1[4] == iVar1) {
          array_move(param_1,param_2 + 1,param_2,param_1[3] - param_2);
        }
        else {
          array_copy(param_1[4],0,iVar1,0,param_2);
          array_copy(param_1[4],param_2 + 1,iVar1,param_2,param_1[3] - param_2);
          jsonp_free(iVar1);
        }
        *(int **)(param_1[4] + param_2 * 4) = param_3;
        param_1[3] = param_1[3] + 1;
        return 0;
      }
      json_decref(param_3);
      return 0xffffffff;
    }
    json_decref(param_3);
  }
  return 0xffffffff;
}

