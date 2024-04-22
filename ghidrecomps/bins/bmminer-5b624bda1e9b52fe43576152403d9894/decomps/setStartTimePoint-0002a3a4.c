
/* WARNING: Unknown calling convention */

void setStartTimePoint(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  time_t tVar4;
  sysinfo sInfo;
  char logstr [256];
  
  iVar1 = sysinfo((sysinfo *)&sInfo);
  pcVar3 = DAT_0002a40c;
  piVar2 = DAT_0002a408;
  if (iVar1 == 0) {
    *DAT_0002a404 = sInfo.uptime;
    *piVar2 = sInfo.uptime + 1;
    sprintf(logstr,pcVar3,sInfo.uptime,sInfo.uptime + 1);
    writeInitLogFile(logstr);
  }
  else {
    piVar2 = __errno_location();
    iVar1 = *piVar2;
    pcVar3 = strerror(iVar1);
    sprintf(logstr,DAT_0002a410,iVar1,pcVar3);
    writeInitLogFile(logstr);
    tVar4 = time((time_t *)0x0);
    piVar2 = DAT_0002a408;
    *DAT_0002a404 = tVar4;
    *piVar2 = tVar4 + 1;
  }
  return;
}

