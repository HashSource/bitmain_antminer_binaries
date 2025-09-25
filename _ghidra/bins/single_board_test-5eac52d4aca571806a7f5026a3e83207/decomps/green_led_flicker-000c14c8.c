
/* WARNING: Unknown calling convention */

int32_t green_led_flicker(void)

{
  int32_t iVar1;
  
  if (ui_pull_thread == 0) {
    routine_init();
  }
  iVar1 = gpio_ctrl_ui(GREEN_LED,UI_FLICKER);
  return iVar1;
}

