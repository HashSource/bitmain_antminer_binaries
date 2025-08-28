
undefined4 power_set_voltage(undefined1 param_1)

{
  int iVar1;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar2;
  
  iVar1 = power_is_support_cmd_package();
  if (iVar1 == 0) {
    power_set_da_value_simple(param_1);
    uVar2 = extraout_r3_00;
  }
  else {
    power_set_da_value(param_1);
    uVar2 = extraout_r3;
  }
  return uVar2;
}

