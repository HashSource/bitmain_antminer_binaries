
undefined4 add_reg_item(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char acStack_414 [1024];
  int local_14;
  
  pthread_mutex_lock((pthread_mutex_t *)reg_scan_mutex);
  local_14 = 0;
  while( true ) {
    if (99 < local_14) {
      pthread_mutex_unlock((pthread_mutex_t *)reg_scan_mutex);
      return 0xffffffff;
    }
    if (*(int *)(&DAT_00047970 + local_14 * 0xc) < 0) break;
    local_14 = local_14 + 1;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_414,0x400,"ADD: chainid=%02x chipaddr=%02x regaddr=%02x regdata=%08x age=%d\n",
             param_1 & 0xff,param_1 >> 8 & 0xff,param_1 >> 0x10 & 0xff,param_2,param_3);
    _applog(2,acStack_414,0);
  }
  iVar1 = local_14 * 0xc;
  *(uint *)(&reg_scan_items + iVar1) = param_1;
  *(undefined4 *)(&DAT_0004796c + iVar1) = param_2;
  *(undefined4 *)(&DAT_00047970 + iVar1) = param_3;
  pthread_mutex_unlock((pthread_mutex_t *)reg_scan_mutex);
  return 1;
}

