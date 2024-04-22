
/* WARNING: Unknown calling convention */

void clean_up(_Bool restarting)

{
  timeval *tv;
  int iVar1;
  int *piVar2;
  char *pcVar3;
  time_t tVar4;
  sysinfo sInfo;
  char tmp42 [2048];
  
  iVar1 = sysinfo((sysinfo *)&sInfo);
  tv = DAT_000244bc;
  if (iVar1 == 0) {
    *DAT_000244b8 = sInfo.uptime;
    cgtime(tv);
  }
  else {
    if (((*DAT_000244ac != '\0') || (*DAT_000244b0 != '\0')) || (5 < *DAT_000244c8)) {
      piVar2 = __errno_location();
      iVar1 = *piVar2;
      pcVar3 = strerror(iVar1);
      snprintf(tmp42,0x800,DAT_000244b4,iVar1,pcVar3);
      _applog(6,tmp42,false);
    }
    tVar4 = time((time_t *)0x0);
    *DAT_000244b8 = tVar4;
    cgtime(DAT_000244bc);
  }
  if (((!restarting) && (*DAT_000244c0 == '\0')) && (*DAT_000244c4 != '\0')) {
    print_summary();
  }
  return;
}

