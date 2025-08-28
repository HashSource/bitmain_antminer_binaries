
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_PWM_according_to_temperature(void)

{
  undefined4 uVar1;
  char tmp42 [2048];
  char logstr [1024];
  int temp_change;
  int pwm_percent;
  
  if ((is218_Temp) || (chip_hasNoMiddle)) {
    temp_highest = dev->temp_top1[0];
  }
  else {
    temp_highest = dev->temp_top1[0];
  }
  if ((temp_highest < 0x4b) && (temp_highest != 0)) {
    if ((1 < temp_highest - last_temperature) || (temp_highest - last_temperature < -1)) {
      if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
        builtin_strncpy(tmp42,"set normal FAN speed...\n",0x18);
        tmp42[0x18] = '\0';
        _applog(5,tmp42,false);
      }
      pwm_percent = (temp_highest + -0x19) * 2;
      if (pwm_percent < 0x14) {
        pwm_percent = 0x14;
      }
      if (100 < pwm_percent) {
        pwm_percent = 100;
      }
      dev->fan_pwm = (uchar)pwm_percent;
      last_temperature = temp_highest;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s: Set PWM percent : %d\n","set_PWM_according_to_temperature",
                 pwm_percent);
        _applog(5,tmp42,false);
      }
      set_PWM((uchar)pwm_percent);
    }
  }
  else {
    set_PWM('d');
    uVar1 = tmp42._20_4_;
    dev->fan_pwm = 'd';
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      builtin_strncpy(tmp42,"set full FAN speed...\n",0x17);
      tmp42[0x17] = SUB41(uVar1,3);
      _applog(5,tmp42,false);
    }
  }
  return;
}

