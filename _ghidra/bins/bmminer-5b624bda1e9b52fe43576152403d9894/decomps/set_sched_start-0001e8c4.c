
/* WARNING: Unknown calling convention */

char * set_sched_start(char *arg)

{
  int iVar1;
  
  iVar1 = sscanf(arg,"%d:%d",0x7714cc,0x7714c8);
  if (iVar1 != 2) {
    return "Invalid time set, should be HH:MM";
  }
  if ((((schedstart.tm.tm_hour < 0x18) && (schedstart.tm.tm_min < 0x3c)) &&
      (-1 < schedstart.tm.tm_hour)) && (-1 < schedstart.tm.tm_min)) {
    schedstart.enable = true;
    return (char *)0x0;
  }
  return "Invalid time set.";
}

