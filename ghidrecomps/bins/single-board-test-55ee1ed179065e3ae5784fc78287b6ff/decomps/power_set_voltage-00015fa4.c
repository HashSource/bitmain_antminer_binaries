
uint power_set_voltage(byte param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = power_is_support_cmd_package();
  if (iVar1 == 0) {
    uVar2 = (uint)param_1;
    power_set_da_value_simple(uVar2);
  }
  else {
    uVar2 = (uint)param_1;
    power_set_da_value(uVar2);
  }
  return uVar2;
}

