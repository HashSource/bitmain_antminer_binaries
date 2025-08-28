
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void setStartTimePoint(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  sysinfo sInfo;
  char logstr [256];
  
  iVar1 = sysinfo((sysinfo *)&sInfo);
  if (iVar1 == 0) {
    total_tv_end_sys = sInfo.uptime + 1;
    total_tv_start_sys = sInfo.uptime;
    sprintf(logstr,"setStartTimePoint total_tv_start_sys=%d total_tv_end_sys=%d\n",sInfo.uptime,
            total_tv_end_sys);
    writeInitLogFile(logstr);
  }
  else {
    piVar2 = __errno_location();
    iVar1 = *piVar2;
    pcVar3 = strerror(iVar1);
    sprintf(logstr,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar1,pcVar3);
    writeInitLogFile(logstr);
    total_tv_start_sys = time((time_t *)0x0);
    total_tv_end_sys = total_tv_start_sys + 1;
  }
  return;
}

