
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_lowprio(void)

{
  int iVar1;
  
  iVar1 = nice(10);
  if ((iVar1 == 0) && (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level))))
  {
    set_lowprio();
    return;
  }
  return;
}

