
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void restart_threads(void)

{
  char tmp42 [2048];
  
  builtin_strncpy(tmp42,"Failed to create restart thread",0x20);
  _applog(3,tmp42,true);
  _quit(1);
  return;
}

