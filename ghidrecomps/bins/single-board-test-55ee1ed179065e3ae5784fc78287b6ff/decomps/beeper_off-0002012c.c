
undefined4 beeper_off(void)

{
  undefined4 uVar1;
  
  uVar1 = gpio_ctrl_ui(0x10,1);
  return uVar1;
}

