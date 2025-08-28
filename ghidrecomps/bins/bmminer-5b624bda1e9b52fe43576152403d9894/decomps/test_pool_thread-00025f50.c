
/* WARNING: Unknown calling convention */

void * test_pool_thread(void *arg)

{
  _Bool _Var1;
  int iVar2;
  int iVar3;
  pthread_t __th;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  char tmp42 [2048];
  
  if (*(char *)((int)arg + 0x6b) == '\0') {
    __th = pthread_self();
    pthread_detach(__th);
  }
  while( true ) {
    if (*(char *)((int)arg + 0x69) != '\0') {
      return (void *)0x0;
    }
    _Var1 = pool_active((pool *)arg,false);
    if (_Var1) break;
    pool_died((pool *)arg);
    if (*(char *)((int)arg + 0x6b) != '\0') goto LAB_00025fec;
    sleep(0x1e);
  }
  pool_tclear((pool *)arg,(_Bool *)((int)arg + 0x61));
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&control_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"test_pool_thread",(char *)0x2982,func,line);
  }
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar2 != 0) {
    _wr_lock((pthread_rwlock_t *)"test_pool_thread",(char *)0x2982,func_00,line_00);
  }
  iVar2 = 0;
  if (pools_active == false) {
                    /* WARNING: Load size is inaccurate */
    iVar2 = *arg;
    pools_active = true;
    currentpool = (pool *)arg;
    if (iVar2 != 0) {
      iVar2 = 1;
    }
  }
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)&control_lock.rwlock);
  if (iVar3 != 0) {
    _rw_unlock((pthread_rwlock_t *)"test_pool_thread",(char *)0x2990,func_01,line_01);
  }
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&control_lock);
  if (iVar3 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"test_pool_thread",(char *)0x2990,func_02,line_02);
  }
  (*selective_yield)();
  if ((iVar2 != 0) && (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level))))
  {
                    /* WARNING: Load size is inaccurate */
    snprintf(tmp42,0x800,"Switching to pool %d %s - first alive pool",*arg,
             *(undefined4 *)((int)arg + 0xa4));
    _applog(5,tmp42,false);
  }
  pool_resus((pool *)arg);
  switch_pools((pool *)0x0);
LAB_00025fec:
  *(undefined1 *)((int)arg + 0x11c) = 0;
  return (void *)0x0;
}

