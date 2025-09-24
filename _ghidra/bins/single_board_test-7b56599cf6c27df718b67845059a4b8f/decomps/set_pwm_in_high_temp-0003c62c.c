
void set_pwm_in_high_temp(int temp)

{
  int temp_local;
  
  gPID.feedback = (float)(longlong)temp;
  pid_calc(&gPID,100);
  set_fan_pwm('d');
  return;
}

