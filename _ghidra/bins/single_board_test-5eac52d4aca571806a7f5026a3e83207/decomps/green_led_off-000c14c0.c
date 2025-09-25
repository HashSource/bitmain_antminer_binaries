
/* WARNING: Unknown calling convention */

int32_t green_led_off(void)

{
  int32_t iVar1;
  
  iVar1 = gpio_ctrl_ui(GREEN_LED,UI_OFF);
  return iVar1;
}

