
undefined power_is_support_cmd_package(void)

{
  undefined uVar1;
  short sVar2;
  
  sVar2 = power_protocal_type;
  if (power_protocal_type != 2) {
    sVar2 = 0;
  }
  uVar1 = (undefined)sVar2;
  if (power_protocal_type == 2) {
    uVar1 = 1;
  }
  return uVar1;
}

