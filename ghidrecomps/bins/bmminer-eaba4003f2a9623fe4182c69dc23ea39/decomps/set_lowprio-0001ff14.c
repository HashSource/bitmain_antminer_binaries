
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_lowprio(void)

{
  int iVar1;
  char tmp42 [2048];
  int ret;
  
  iVar1 = nice(10);
  if ((iVar1 == 0) && (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level))))
  {
    builtin_strncpy(tmp42,"Unable to set thread to low priority",0x24);
    tmp42[0x24] = '\0';
    _applog(6,tmp42,false);
  }
  return;
}

