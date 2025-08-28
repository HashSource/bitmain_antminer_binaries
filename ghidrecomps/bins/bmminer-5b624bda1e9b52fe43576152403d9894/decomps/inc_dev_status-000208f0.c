
/* WARNING: Unknown calling convention */

void inc_dev_status(int max_fan,int max_temp)

{
  int iVar1;
  char *func;
  char *func_00;
  int line;
  int line_00;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"inc_dev_status",(char *)0x21d3,func,line);
  }
  g_max_fan = max_fan;
  g_max_temp = max_temp;
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"inc_dev_status",(char *)0x21d6,func_00,line_00);
  }
  (*selective_yield)();
  return;
}

