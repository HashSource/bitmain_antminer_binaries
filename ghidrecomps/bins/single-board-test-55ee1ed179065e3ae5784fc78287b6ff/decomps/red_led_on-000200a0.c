
undefined4 red_led_on(void)

{
  undefined4 uVar1;
  
  uVar1 = gpio_ctrl_ui(1,0);
  return uVar1;
}

