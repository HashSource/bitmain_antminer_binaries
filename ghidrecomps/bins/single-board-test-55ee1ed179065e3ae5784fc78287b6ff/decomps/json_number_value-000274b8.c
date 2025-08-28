
undefined4 json_number_value(int *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 3)) {
    if ((param_1 == (int *)0x0) || (*param_1 != 4)) {
      uVar1 = 0;
    }
    else {
      uVar1 = json_real_value(param_1);
    }
  }
  else {
    uVar2 = json_integer_value(param_1);
    uVar1 = __aeabi_l2d((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  }
  return uVar1;
}

