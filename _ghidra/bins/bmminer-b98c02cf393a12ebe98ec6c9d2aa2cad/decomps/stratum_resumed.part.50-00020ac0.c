
void stratum_resumed_part_50(undefined4 *param_1)

{
  char acStack_808 [2048];
  
  if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
    pool_resus(param_1);
    return;
  }
  snprintf(acStack_808,0x800,"Stratum connection to pool %d resumed",*param_1);
  _applog(6,acStack_808,0);
  pool_resus(param_1);
  return;
}

