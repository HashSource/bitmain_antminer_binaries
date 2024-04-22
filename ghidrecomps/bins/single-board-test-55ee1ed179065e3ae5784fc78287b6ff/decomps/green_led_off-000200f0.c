
undefined4 green_led_off(void)

{
  undefined4 uVar1;
  
  uVar1 = gpio_ctrl_ui(2,1);
  return uVar1;
}

