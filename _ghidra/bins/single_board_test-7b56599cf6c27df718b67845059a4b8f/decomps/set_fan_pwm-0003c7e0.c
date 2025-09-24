
void set_fan_pwm(uint8_t pwm_percent)

{
  uint duty;
  uint8_t pwm_percent_local;
  char time_stamp [48];
  char tmp1 [256];
  int32_t temp_pwm_percent;
  uint16_t pwm_low_value;
  uint16_t pwm_high_value;
  
  if (set_fan_pwm::pwm_ctx == 0) {
    set_fan_pwm::pwm_ctx = pwm_init(PWM_CTRL_FAN,100000);
  }
  if ((-1 < set_fan_pwm::pwm_ctx) && ((uint)pwm_percent != last_pwm)) {
    duty = (uint)pwm_percent;
    pwm_set(set_fan_pwm::pwm_ctx,duty);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set PWM success , current pwm is : %d\n","set_fan_pwm",duty);
    snprintf(tmp1,0x100,"Set PWM success , current pwm is : %d",duty);
    log_to_file(tmp1,time_stamp);
    last_pwm = duty;
  }
  return;
}

