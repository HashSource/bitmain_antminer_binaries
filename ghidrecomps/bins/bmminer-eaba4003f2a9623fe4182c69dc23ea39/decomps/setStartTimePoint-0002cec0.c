
/* WARNING: Unknown calling convention */

void setStartTimePoint(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char tmp42 [2048];
  sysinfo sInfo;
  char logstr [256];
  
  iVar1 = sysinfo((sysinfo *)&sInfo);
  if (iVar1 == 0) {
    total_tv_start_sys = sInfo.uptime;
    total_tv_end_sys = sInfo.uptime + 1;
    sprintf(logstr,"setStartTimePoint total_tv_start_sys=%d total_tv_end_sys=%d\n",sInfo.uptime,
            total_tv_end_sys);
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"%s",logstr);
      _applog(5,tmp42,false);
    }
  }
  else {
    piVar2 = __errno_location();
    iVar1 = *piVar2;
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    sprintf(logstr,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar1,pcVar3);
    total_tv_start_sys = time((time_t *)0x0);
    total_tv_end_sys = total_tv_start_sys + 1;
  }
  return;
}

