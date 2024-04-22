
undefined4 power_set_voltage(undefined param_1)

{
  int iVar1;
  
  iVar1 = power_is_support_cmd_package();
  if (iVar1 == 0) {
    power_set_da_value_simple(param_1);
  }
  else {
    power_set_da_value(param_1);
  }
  return 0;
}

