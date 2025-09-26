
/* WARNING: Unknown calling convention */

int32_t red_led_on(void)

{
  int32_t iVar1;
  
  iVar1 = gpio_ctrl_ui(RED_LED,UI_ON);
  return iVar1;
}

