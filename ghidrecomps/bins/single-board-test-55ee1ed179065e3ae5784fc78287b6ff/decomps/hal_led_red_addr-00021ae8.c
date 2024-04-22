
undefined4 hal_led_red_addr(void)

{
  undefined4 uVar1;
  
  uVar1 = red_addr;
  if (conf_loaded == 0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

