
undefined4 priority_pool_part_9(int param_1)

{
  char acStack_808 [2048];
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
    snprintf(acStack_808,0x800,"WTF No pool %d found!",param_1);
    _applog(3,acStack_808,0);
  }
  return *(undefined4 *)(pools + param_1 * 4);
}

