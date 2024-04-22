
void show_nonce_detail(void)

{
  undefined2 local_4a8 [512];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  char acStack_98 [64];
  char acStack_58 [64];
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_18 = (uint)gChain;
  local_c = 0;
  memset(acStack_58,0,0x40);
  memset(acStack_98,0,0x40);
  local_10 = 0;
  local_14 = 0;
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    local_a0 = 0;
    local_9c = 0;
    sprintf((char *)&local_a0,"%03d ",
            *(undefined4 *)(one_work_nonce_each_asic + (local_18 * 3 + local_c) * 4));
    strcat(acStack_58,(char *)&local_a0);
    local_a8 = 0;
    local_a4 = 0;
    sprintf((char *)&local_a8,"%03d ",
            *(undefined4 *)(one_work_invalid_nonce_each_asic_2 + (local_18 * 3 + local_c) * 8 + 4));
    strcat(acStack_98,(char *)&local_a8);
    local_10 = local_10 + *(int *)(one_work_nonce_each_asic + (local_18 * 3 + local_c) * 4);
    local_14 = local_14 +
               *(int *)(one_work_invalid_nonce_each_asic_2 + (local_18 * 3 + local_c) * 8 + 4);
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf((char *)local_4a8,0x400,"valid:    %s total=%d\n",acStack_58,local_10);
    _applog(2,local_4a8,0);
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf((char *)local_4a8,0x400,"invalid:  %s total=%d\n",acStack_98,local_14);
    _applog(2,local_4a8,0);
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_4a8[0] = 10;
    _applog(2,local_4a8,0);
  }
  return;
}

