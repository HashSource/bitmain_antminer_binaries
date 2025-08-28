
undefined1 * power_get_voltage(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = power_is_support_cmd_package();
  if (iVar2 == 0) {
    uVar1 = power_get_da_value_simple();
    *param_1 = uVar1;
  }
  else {
    uVar1 = power_get_da_value();
    *param_1 = uVar1;
  }
  return param_1;
}

