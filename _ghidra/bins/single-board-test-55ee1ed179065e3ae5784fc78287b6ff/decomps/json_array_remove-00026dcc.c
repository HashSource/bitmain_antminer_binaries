
undefined4 json_array_remove(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 1)) {
    uVar1 = 0xffffffff;
  }
  else if (param_2 < (uint)param_1[3]) {
    json_decref(*(undefined4 *)(param_1[4] + param_2 * 4));
    if (param_2 < param_1[3] - 1U) {
      array_move(param_1,param_2,param_2 + 1,(param_1[3] - param_2) + -1);
    }
    param_1[3] = param_1[3] + -1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

