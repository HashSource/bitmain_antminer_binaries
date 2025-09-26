
/* WARNING: Unknown calling convention */

int32_t beeper_off(void)

{
  int32_t iVar1;
  
  iVar1 = gpio_ctrl_ui(BEEP_1,UI_OFF);
  return iVar1;
}

