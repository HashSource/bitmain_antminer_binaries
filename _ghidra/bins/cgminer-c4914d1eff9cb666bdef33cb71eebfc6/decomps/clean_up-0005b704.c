
void clean_up(_Bool restarting)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  _Bool restarting_local;
  char tmp42 [2048];
  sysinfo sInfo;
  
  iVar1 = sysinfo((sysinfo *)&sInfo);
  if (iVar1 == 0) {
    total_tv_end_sys = sInfo.uptime;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      piVar2 = __errno_location();
      iVar1 = *piVar2;
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar1,pcVar3);
      _applog(6,tmp42,false);
    }
    total_tv_end_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_end);
  if (((!restarting) && (opt_realquiet != true)) && (successful_connect != false)) {
    print_summary();
  }
  return;
}

