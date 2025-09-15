
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void restart_threads(void)

{
  int iVar1;
  pthread_t rthread;
  
  cgtime(&restart_tv_start);
  iVar1 = pthread_create(&rthread,(pthread_attr_t *)0x0,(__start_routine *)0x283f1,(void *)0x0);
  if (iVar1 != 0) {
    restart_threads();
  }
  return;
}

