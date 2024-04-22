
void setStartTimePoint(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  sysinfo local_150;
  char acStack_110 [256];
  
  iVar1 = sysinfo(&local_150);
  if (iVar1 == 0) {
    total_tv_end_sys = local_150.uptime + 1;
    total_tv_start_sys = local_150.uptime;
    sprintf(acStack_110,"setStartTimePoint total_tv_start_sys=%d total_tv_end_sys=%d\n",
            local_150.uptime,total_tv_end_sys);
    writeInitLogFile(acStack_110);
    return;
  }
  piVar2 = __errno_location();
  iVar1 = *piVar2;
  pcVar3 = strerror(iVar1);
  sprintf(acStack_110,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar1,pcVar3);
  writeInitLogFile(acStack_110);
  total_tv_start_sys = time((time_t *)0x0);
  total_tv_end_sys = total_tv_start_sys + 1;
  return;
}

