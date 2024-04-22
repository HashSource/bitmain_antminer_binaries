
void set_PWM(uchar pwm_percent)

{
  uchar pwm_percent_local;
  uint16_t pwm_low_value;
  uint16_t pwm_high_value;
  int temp_pwm_percent;
  
  temp_pwm_percent = (int)pwm_percent;
  if ((uint)temp_pwm_percent < 0x14) {
    temp_pwm_percent = 0x14;
  }
  if (100 < (uint)temp_pwm_percent) {
    temp_pwm_percent = 100;
  }
  _pwm_low_value =
       CONCAT22((short)((uint)(temp_pwm_percent * 0x32) / 100),
                (short)((temp_pwm_percent * -0x32 + 5000) / 100));
  dev->pwm_value = _pwm_low_value;
  dev->pwm_percent = (uchar)temp_pwm_percent;
  set_fan_control(dev->pwm_value);
  return;
}

