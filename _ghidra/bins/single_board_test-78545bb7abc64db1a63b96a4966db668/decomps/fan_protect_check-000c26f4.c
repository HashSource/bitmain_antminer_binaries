
/* WARNING: Unknown calling convention */

_Bool fan_protect_check(void)

{
  _Bool _Var1;
  
  fan_turn_on(BOTH_SIZE);
  pwm_set(gFan,100);
  lcd_common_show("Check fan","speed","waiting...");
  _Var1 = fan_speed_check();
  if (!_Var1) {
    show_fan_speed_protect_and_exit();
  }
  return _Var1;
}

