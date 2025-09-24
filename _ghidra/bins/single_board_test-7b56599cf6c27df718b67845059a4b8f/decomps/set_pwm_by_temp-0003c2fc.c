
void set_pwm_by_temp(int temp)

{
  int temp_local;
  
  if (!is_init_pid_parms) {
    init_pid_parms();
  }
  if (temp < 0x3b) {
    set_pwm_by_pid(temp);
  }
  else {
    set_pwm_in_high_temp(temp);
  }
  return;
}

