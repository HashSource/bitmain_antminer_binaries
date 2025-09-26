
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void show_fan_speed_protect_and_exit(void)

{
  lcd_common_show("Fan speed err","exit test",(char *)0x0);
  pwm_set(gFan,100);
  sleep(5);
  return;
}

