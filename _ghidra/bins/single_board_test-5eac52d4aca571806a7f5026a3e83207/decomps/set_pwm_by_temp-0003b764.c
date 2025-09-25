
void set_pwm_by_temp(int temp)

{
  int temp_local;
  
  if (!is_init_pid_parms) {
    init_pid_parms();
  }
  set_pwm_by_pid(temp);
  return;
}

