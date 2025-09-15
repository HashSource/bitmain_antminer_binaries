
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void wake_gws(void)

{
  int iVar1;
  char *func;
  char *func_00;
  int line;
  int line_00;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)stgd_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"wake_gws",(char *)0x1494,func,line);
  }
  pthread_cond_signal((pthread_cond_t *)&gws_cond);
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)stgd_lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"wake_gws",(char *)0x1496,func_00,line_00);
  }
  (*selective_yield)();
  return;
}

