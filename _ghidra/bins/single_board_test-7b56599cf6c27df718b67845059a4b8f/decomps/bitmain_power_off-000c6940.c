
/* WARNING: Unknown calling convention */

int32_t bitmain_power_off(void)

{
  int32_t iVar1;
  
  iVar1 = is_gpio_exist(0x38b);
  if (iVar1 == 0) {
    gpio_export(0x38b);
    gpio_direction(0x38b,DIRECTION_OUT);
  }
  iVar1 = gpio_write(0x38b,'\x01');
  return iVar1;
}

