
undefined4 hal_led_green_addr(void)

{
  undefined4 uVar1;
  
  uVar1 = green_addr;
  if (conf_loaded == 0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

