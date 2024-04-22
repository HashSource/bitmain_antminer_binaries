
undefined8 json_number_value(int *param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 3)) {
    if ((param_1 == (int *)0x0) || (*param_1 != 4)) {
      uVar1 = 0;
    }
    else {
      uVar1 = json_real_value(param_1);
    }
  }
  else {
    uVar1 = json_integer_value(param_1);
    uVar1 = __aeabi_l2d((int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  }
  return uVar1;
}

