
undefined4 beeper_on(void)

{
  undefined4 uVar1;
  
  uVar1 = gpio_ctrl_ui(0x10,0);
  return uVar1;
}

