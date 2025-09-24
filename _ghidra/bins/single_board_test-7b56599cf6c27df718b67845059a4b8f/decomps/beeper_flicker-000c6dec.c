
/* WARNING: Unknown calling convention */

int32_t beeper_flicker(void)

{
  int32_t iVar1;
  
  if (ui_pull_thread == 0) {
    routine_init();
  }
  iVar1 = gpio_ctrl_ui(BEEP_1,UI_FLICKER);
  return iVar1;
}

