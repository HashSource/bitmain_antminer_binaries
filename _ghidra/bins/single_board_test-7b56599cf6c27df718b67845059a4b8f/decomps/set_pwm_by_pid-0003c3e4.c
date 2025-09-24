
void set_pwm_by_pid(int temp)

{
  int iVar1;
  int32_t iVar2;
  float fVar3;
  uint8_t local_148;
  int temp_local;
  char time_stamp [48];
  char tmp1 [256];
  int pwm_percent_set;
  
  if (set_pwm_by_pid::pwm_percent_pid == -10000.0) {
    iVar2 = get_curr_pwm();
    set_pwm_by_pid::pwm_percent_pid = (float)(longlong)iVar2;
  }
  gPID.feedback = (float)(longlong)temp;
  fVar3 = pid_calc(&gPID,(int)set_pwm_by_pid::pwm_percent_pid);
  set_pwm_by_pid::pwm_percent_pid = fVar3 + set_pwm_by_pid::pwm_percent_pid;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : feedback: %f, input: %f\n\n","set_pwm_by_pid",SUB84((double)gPID.feedback,0),
         (int)((ulonglong)(double)gPID.feedback >> 0x20),(double)set_pwm_by_pid::pwm_percent_pid);
  snprintf(tmp1,0x100,"feedback: %f, input: %f\n",tmp1,(double)gPID.feedback,
           (double)set_pwm_by_pid::pwm_percent_pid);
  log_to_file(tmp1,time_stamp);
  iVar1 = (int)(longlong)(set_pwm_by_pid::pwm_percent_pid + 0.5);
  iVar2 = get_curr_pwm();
  if (iVar2 != iVar1) {
    fVar3 = gPID.min_limit;
    if (-1 < (int)((uint)((float)(longlong)iVar1 < gPID.min_limit) << 0x1f)) {
      fVar3 = (float)(longlong)iVar1;
    }
    if (fVar3 <= gPID.max_limit) {
      if ((int)((uint)((float)(longlong)iVar1 < gPID.min_limit) << 0x1f) < 0) {
        local_148 = (0.0 < gPID.min_limit) * (char)(int)gPID.min_limit;
      }
      else {
        local_148 = (0.0 < (float)(longlong)iVar1) * (char)(int)(float)(longlong)iVar1;
      }
    }
    else {
      local_148 = (0.0 < gPID.max_limit) * (char)(int)gPID.max_limit;
    }
    set_fan_pwm(local_148);
  }
  return;
}

