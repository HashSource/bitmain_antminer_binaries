
float pid_calc(PID *pid,int pwm_percent_pid_current)

{
  bool bVar1;
  int pwm_percent_pid_current_local;
  PID *pid_local;
  float ed;
  float ei;
  float ep;
  float out;
  
  pid->e_0 = pid->target - pid->feedback;
  if (pid_calc::flag != true) {
    pid->e_1 = pid->e_0;
    pid->e_2 = pid->e_0;
    pid_calc::flag = true;
  }
  out = pid->Kp * (pid->e_0 - pid->e_1) + pid->Ki * pid->e_0 +
        pid->Kd * ((pid->e_0 - (pid->e_1 + pid->e_1)) + pid->e_2);
  if ((float)(longlong)pwm_percent_pid_current + out <= pid->max_limit) {
    if ((int)((uint)((float)(longlong)pwm_percent_pid_current + out < pid->min_limit) << 0x1f) < 0)
    {
      out = pid->min_limit - (float)(longlong)pwm_percent_pid_current;
    }
  }
  else {
    out = pid->max_limit - (float)(longlong)pwm_percent_pid_current;
  }
  pid->e_2 = pid->e_1;
  pid->e_1 = pid->e_0;
  bVar1 = 0xfffffffe < (uint)pid_calc::counter;
  pid_calc::counter._0_4_ = (uint)pid_calc::counter + 1;
  pid_calc::counter._4_4_ = pid_calc::counter._4_4_ + (uint)bVar1;
  return out;
}

