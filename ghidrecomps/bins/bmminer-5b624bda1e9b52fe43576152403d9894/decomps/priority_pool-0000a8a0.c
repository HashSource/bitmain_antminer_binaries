
/* WARNING: Unknown calling convention */

pool * priority_pool(int choice)

{
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
    snprintf(tmp42,0x800,"WTF No pool %d found!",choice);
    _applog(3,tmp42,false);
  }
  return pools[choice];
}

