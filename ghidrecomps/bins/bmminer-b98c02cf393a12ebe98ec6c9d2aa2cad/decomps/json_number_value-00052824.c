
undefined8 json_number_value(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  if (param_1 == (int *)0x0) {
    return DAT_00052858;
  }
  if (*param_1 != 3) {
    if (*param_1 != 4) {
      return DAT_00052858;
    }
    return *(undefined8 *)(param_1 + 2);
  }
  uVar1 = __aeabi_l2d(param_1[2],param_1[3],param_3,3,param_4);
  return uVar1;
}

