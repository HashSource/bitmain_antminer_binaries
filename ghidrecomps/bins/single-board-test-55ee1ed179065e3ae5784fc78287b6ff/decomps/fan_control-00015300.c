
void fan_control(undefined param_1)

{
  if (fan_pwm_handle == 0) {
    fan_pwm_handle = pwm_init(0,100);
  }
  printf("--- %s\n","fan_control");
  pwm_set(fan_pwm_handle,param_1);
  return;
}

