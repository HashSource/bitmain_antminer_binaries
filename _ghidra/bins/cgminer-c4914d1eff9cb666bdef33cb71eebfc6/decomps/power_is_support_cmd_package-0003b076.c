
/* WARNING: Unknown calling convention */

_Bool power_is_support_cmd_package(void)

{
  undefined1 uVar1;
  uint16_t uVar2;
  
  uVar2 = power_protocal_type;
  if (power_protocal_type == 2) {
    uVar2 = 1;
  }
  uVar1 = (undefined1)uVar2;
  if (power_protocal_type != 2) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

