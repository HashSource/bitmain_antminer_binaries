
void clean_up(int param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  sysinfo local_850;
  char acStack_810 [2052];
  
  iVar1 = sysinfo(&local_850);
  if (iVar1 == 0) {
    total_tv_end_sys = local_850.uptime;
    cgtime(DAT_000203f4);
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      piVar2 = __errno_location();
      iVar1 = *piVar2;
      pcVar3 = strerror(iVar1);
      snprintf(acStack_810,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar1,pcVar3);
      _applog(6,acStack_810,0);
    }
    total_tv_end_sys = time((time_t *)0x0);
    cgtime(DAT_000203f4);
  }
  if (((param_1 == 0) && (opt_realquiet == '\0')) && (successful_connect != '\0')) {
    print_summary();
    return;
  }
  return;
}

