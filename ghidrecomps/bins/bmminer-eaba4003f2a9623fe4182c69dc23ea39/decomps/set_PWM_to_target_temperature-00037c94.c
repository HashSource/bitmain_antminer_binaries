
/* WARNING: Unknown calling convention */

void set_PWM_to_target_temperature(void)

{
  int iVar1;
  int iVar2;
  char tmp42 [2048];
  int pwm_percent;
  int max_chip_temp;
  int temp_diff;
  
  iVar1 = dev->temp_top1[1];
  if (target_temp < iVar1) {
    iVar2 = iVar1 - target_temp;
  }
  else {
    iVar2 = target_temp - iVar1;
  }
  if (2 < iVar2) {
    if (iVar1 < target_temp) {
      iVar2 = dev->pwm_percent - 2;
    }
    else {
      iVar2 = dev->pwm_percent + 2;
    }
    if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"target temp: %d,  current temp: %d, current pwm: %d\n",target_temp,iVar1
               ,(uint)dev->pwm_percent);
      _applog(5,tmp42,false);
    }
    set_PWM((uchar)iVar2);
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"pwm_percent: %d\n",iVar2);
      _applog(5,tmp42,false);
    }
    sleep(2);
  }
  return;
}

