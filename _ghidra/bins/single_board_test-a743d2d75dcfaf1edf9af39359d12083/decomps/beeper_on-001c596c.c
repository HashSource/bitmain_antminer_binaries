
/* WARNING: Unknown calling convention */

int32_t beeper_on(void)

{
  int32_t iVar1;
  
  iVar1 = gpio_ctrl_ui(BEEP_1,UI_ON);
  return iVar1;
}

