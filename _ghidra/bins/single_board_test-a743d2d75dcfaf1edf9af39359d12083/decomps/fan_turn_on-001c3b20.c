
/* WARNING: Unknown calling convention */

int32_t fan_turn_on(bitmain_fan_side_e side)

{
  int32_t iVar1;
  int32_t iVar2;
  
  if (side == FRONT_SIDE) {
    iVar1 = gpio_write(0x3ba,'\x01');
    return iVar1;
  }
  if (side == REAR_SIDE) {
    iVar1 = gpio_write(0x3bb,'\x01');
    return iVar1;
  }
  iVar1 = gpio_write(0x3ba,'\x01');
  iVar2 = gpio_write(0x3bb,'\x01');
  return iVar2 + iVar1;
}

