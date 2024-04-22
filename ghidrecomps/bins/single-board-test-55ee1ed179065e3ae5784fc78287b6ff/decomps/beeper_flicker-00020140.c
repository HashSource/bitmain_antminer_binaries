
undefined4 beeper_flicker(void)

{
  undefined4 uVar1;
  
  uVar1 = gpio_ctrl_ui(0x10,2);
  return uVar1;
}

