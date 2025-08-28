
undefined1 power_is_support_cmd_package(void)

{
  undefined1 uVar1;
  short sVar2;
  
  sVar2 = power_protocal_type;
  if (power_protocal_type == 2) {
    sVar2 = 1;
  }
  uVar1 = (undefined1)sVar2;
  if (power_protocal_type != 2) {
    uVar1 = 0;
  }
  return uVar1;
}

