
/* WARNING: Unknown calling convention */

void restart_threads(void)

{
  int iVar1;
  pthread_t rthread;
  
  cgtime(DAT_0001fe48);
  iVar1 = pthread_create(&rthread,(pthread_attr_t *)0x0,DAT_0001fe4c,(void *)0x0);
  if (iVar1 != 0) {
    restart_threads();
  }
  return;
}

