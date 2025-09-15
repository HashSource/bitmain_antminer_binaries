
/* WARNING: Unknown calling convention */

_Bool is_env_temperature_high(void)

{
  int high_pwm_threshold;
  
  return 0x4f < dev->pwm_percent;
}

