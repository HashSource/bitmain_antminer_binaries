
/* WARNING: Unknown calling convention */

void check_domain_volt(void)

{
  int iVar1;
  char tmp42 [2048];
  int ret;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"in %s @line %d","check_domain_volt",0x2099);
    _applog(5,tmp42,false);
  }
  while( true ) {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"in %s @line %d==========prress enter to continue==========",
               "check_domain_volt",0x209d);
      _applog(5,tmp42,false);
    }
    iVar1 = getchar();
    if (iVar1 == 10) break;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"in %s @line %d==========prress enter to continue==========",
               "check_domain_volt",0x20a0);
      _applog(5,tmp42,false);
    }
    usleep(1000000);
  }
  return;
}

