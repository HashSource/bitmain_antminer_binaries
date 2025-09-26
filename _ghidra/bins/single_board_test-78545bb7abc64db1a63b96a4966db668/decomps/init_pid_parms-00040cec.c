
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void init_pid_parms(void)

{
  gPID.startup_Kp = -9.0;
  gPID.Kp = -9.5;
  gPID.Ki = -1.0;
  gPID.Kd = 0.0;
  gPID.target = 57.0;
  gPID.min_limit = 20.0;
  gPID.max_limit = 100.0;
  is_init_pid_parms = true;
  return;
}

