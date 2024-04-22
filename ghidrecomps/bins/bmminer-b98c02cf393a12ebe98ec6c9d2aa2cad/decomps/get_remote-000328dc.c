
int get_remote(short param_1)

{
  double dVar1;
  short local_814;
  char acStack_810 [2052];
  
  dVar1 = ((double)(longlong)(int)(short)(param_1 + -0x40) * DAT_00032978 - DAT_00032980) /
          DAT_00032988;
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_810,0x800,"remote : %d temp : %f",(int)(short)(param_1 + -0x40),
             (double)(float)dVar1);
    _applog(7,acStack_810,0);
  }
  local_814 = (short)(int)dVar1;
  return (int)local_814;
}

