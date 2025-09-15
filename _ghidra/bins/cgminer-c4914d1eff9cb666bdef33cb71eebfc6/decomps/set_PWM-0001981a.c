
void set_PWM(uchar pwm_percent)

{
  FILE *__stream;
  uchar pwm_percent_local;
  FILE *pFile;
  uint16_t pwm_low_value;
  uint16_t pwm_high_value;
  int temp_pwm_percent;
  
  temp_pwm_percent = (int)pwm_percent;
  if ((uint)temp_pwm_percent < 5) {
    temp_pwm_percent = 5;
  }
  if (100 < (uint)temp_pwm_percent) {
    temp_pwm_percent = 100;
  }
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: fan pwm = %d\n","temperature.c",0x5b6,"set_PWM",temp_pwm_percent);
    }
    fclose(__stream);
  }
  _pwm_low_value =
       CONCAT22((short)((uint)(temp_pwm_percent * 0x32) / 100),
                (short)(((100 - temp_pwm_percent) * 0x32) / 100));
  dev->pwm_value = _pwm_low_value;
  dev->pwm_percent = (uchar)temp_pwm_percent;
  set_fan_control(dev->pwm_value);
  dev->fan_pwm = dev->pwm_percent;
  return;
}

