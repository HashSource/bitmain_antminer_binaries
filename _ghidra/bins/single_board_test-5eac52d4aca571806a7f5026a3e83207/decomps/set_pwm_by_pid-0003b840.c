
void set_pwm_by_pid(int temp)

{
  int iVar1;
  int32_t iVar2;
  float fVar3;
  uint8_t local_118;
  int temp_local;
  int pwm_percent_set;
  
  if (set_pwm_by_pid::pwm_percent_pid == -10000.0) {
    iVar2 = get_curr_pwm();
    set_pwm_by_pid::pwm_percent_pid = (float)(longlong)iVar2;
  }
  gPID.feedback = (float)(longlong)temp;
  fVar3 = pid_calc(&gPID,(int)set_pwm_by_pid::pwm_percent_pid);
  set_pwm_by_pid::pwm_percent_pid = fVar3 + set_pwm_by_pid::pwm_percent_pid;
  iVar1 = (int)(longlong)(set_pwm_by_pid::pwm_percent_pid + 0.5);
  iVar2 = get_curr_pwm();
  if (iVar2 != iVar1) {
    fVar3 = gPID.min_limit;
    if (-1 < (int)((uint)((float)(longlong)iVar1 < gPID.min_limit) << 0x1f)) {
      fVar3 = (float)(longlong)iVar1;
    }
    if (fVar3 <= gPID.max_limit) {
      if ((int)((uint)((float)(longlong)iVar1 < gPID.min_limit) << 0x1f) < 0) {
        local_118 = (0.0 < gPID.min_limit) * (char)(int)gPID.min_limit;
      }
      else {
        local_118 = (0.0 < (float)(longlong)iVar1) * (char)(int)(float)(longlong)iVar1;
      }
    }
    else {
      local_118 = (0.0 < gPID.max_limit) * (char)(int)gPID.max_limit;
    }
    set_fan_pwm(local_118);
  }
  return;
}

