
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_highprio(void)

{
  int iVar1;
  char tmp42 [2048];
  int ret;
  
  iVar1 = nice(-10);
  if (((iVar1 == 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    builtin_strncpy(tmp42,"Unable to set thread to high priorit",0x24);
    tmp42[0x24] = 'y';
    tmp42[0x25] = '\0';
    _applog(7,tmp42,false);
  }
  return;
}

