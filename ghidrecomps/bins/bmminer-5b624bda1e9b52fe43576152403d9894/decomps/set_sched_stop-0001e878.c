
/* WARNING: Unknown calling convention */

char * set_sched_stop(char *arg)

{
  int iVar1;
  
  iVar1 = sscanf(arg,"%d:%d",0x7703d4,0x7703d0);
  if (iVar1 != 2) {
    return "Invalid time set, should be HH:MM";
  }
  if ((((schedstop.tm.tm_hour < 0x18) && (schedstop.tm.tm_min < 0x3c)) &&
      (-1 < schedstop.tm.tm_hour)) && (-1 < schedstop.tm.tm_min)) {
    schedstop.enable = true;
    return (char *)0x0;
  }
  return "Invalid time set.";
}

