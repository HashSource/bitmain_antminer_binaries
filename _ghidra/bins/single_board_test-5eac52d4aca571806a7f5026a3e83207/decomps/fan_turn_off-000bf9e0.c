
/* WARNING: Unknown calling convention */

int32_t fan_turn_off(bitmain_fan_side_e side)

{
  int32_t iVar1;
  int32_t iVar2;
  
  if (side == FRONT_SIDE) {
    iVar1 = gpio_write(0x3ba,'\0');
    return iVar1;
  }
  if (side == REAR_SIDE) {
    iVar1 = gpio_write(0x3bb,'\0');
    return iVar1;
  }
  iVar1 = gpio_write(0x3ba,'\0');
  iVar2 = gpio_write(0x3bb,'\0');
  return iVar2 + iVar1;
}

