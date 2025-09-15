
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void restart_threads(void)

{
  int iVar1;
  char tmp42 [2048];
  pthread_t rthread;
  
  cgtime(&restart_tv_start);
  iVar1 = pthread_create(&rthread,(pthread_attr_t *)0x0,restart_thread,(void *)0x0);
  if (iVar1 != 0) {
    builtin_strncpy(tmp42,"Failed to create restart thread",0x20);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

