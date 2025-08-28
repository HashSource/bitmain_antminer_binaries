
/* WARNING: Unknown calling convention */

void clean_up(_Bool restarting)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  sysinfo sInfo;
  char tmp42 [2048];
  
  iVar1 = sysinfo((sysinfo *)&sInfo);
  if (iVar1 == 0) {
    total_tv_end_sys = sInfo.uptime;
    cgtime(&total_tv_end);
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      piVar2 = __errno_location();
      iVar1 = *piVar2;
      pcVar3 = strerror(iVar1);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar1,pcVar3);
      _applog(6,tmp42,false);
    }
    total_tv_end_sys = time((time_t *)0x0);
    cgtime(&total_tv_end);
  }
  if (((!restarting) && (opt_realquiet == false)) && (successful_connect != false)) {
    print_summary();
  }
  return;
}

