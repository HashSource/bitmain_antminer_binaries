
undefined4 json_array_get(int *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 1)) {
    uVar1 = 0;
  }
  else if (param_2 < (uint)param_1[3]) {
    uVar1 = *(undefined4 *)(param_1[4] + param_2 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

