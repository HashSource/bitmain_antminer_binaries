
void process_version_mask_part_6(undefined4 *param_1)

{
  char acStack_808 [2048];
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
    snprintf(acStack_808,0x800,"Pool %d rolling mask do not match!",*param_1);
    _applog(5,acStack_808,0);
  }
  *(undefined *)(param_1 + 0xa1) = 0;
  param_1[0xa2] = 1;
  return;
}

