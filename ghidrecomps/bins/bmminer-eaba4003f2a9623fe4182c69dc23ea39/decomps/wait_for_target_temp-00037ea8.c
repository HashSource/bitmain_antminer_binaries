
/* WARNING: Unknown calling convention */

void wait_for_target_temp(void)

{
  _Bool _Var1;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"wait for target temp %d, current temp is %d",target_temp,dev->temp_top1[1]
            );
    _applog(5,tmp42,false);
  }
  while (_Var1 = is_temp_adjusted_to_target(), !_Var1) {
    sleep(1);
  }
  return;
}

