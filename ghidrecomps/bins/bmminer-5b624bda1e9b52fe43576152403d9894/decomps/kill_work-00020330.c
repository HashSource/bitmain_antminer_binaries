
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void kill_work(void)

{
  char tmp42 [2048];
  
  cg_completion_timeout((void *)0x22971,(void *)0x0,5000);
  builtin_strncpy(tmp42,"Shutdown signal received",0x18);
  tmp42[0x18] = '.';
  tmp42[0x19] = '\0';
  _applog(3,tmp42,true);
  _quit(0);
  return;
}

