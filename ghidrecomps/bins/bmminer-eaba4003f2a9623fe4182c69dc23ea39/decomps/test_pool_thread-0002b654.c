
void * test_pool_thread(void *arg)

{
  _Bool _Var1;
  pthread_t __th;
  bool bVar2;
  void *arg_local;
  char tmp42 [2048];
  pool *pool;
  _Bool first_pool;
  
  if (*(char *)((int)arg + 0x6f) != '\x01') {
    __th = pthread_self();
    pthread_detach(__th);
  }
  while( true ) {
    if (*(char *)((int)arg + 0x6d) != '\0') {
      return (void *)0x0;
    }
    _Var1 = pool_active((pool *)arg,false);
    if (_Var1) break;
    pool_died((pool *)arg);
    if (*(char *)((int)arg + 0x6f) == '\x01') goto LAB_0002b7d2;
    sleep(0x1e);
  }
  pool_tclear((pool *)arg,(_Bool *)((int)arg + 99));
  bVar2 = false;
  _cg_wlock(&control_lock,"cgminer.c","test_pool_thread",0x2989);
  if (pools_active != true) {
                    /* WARNING: Load size is inaccurate */
    bVar2 = *arg != 0;
    pools_active = true;
    currentpool = (pool *)arg;
  }
  _cg_wunlock(&control_lock,"cgminer.c","test_pool_thread",0x2997);
  if ((bVar2) && (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
    snprintf(tmp42,0x800,"Switching to pool %d %s - first alive pool",*arg,
             *(undefined4 *)((int)arg + 0xac));
    _applog(5,tmp42,false);
  }
  pool_resus((pool *)arg);
  switch_pools((pool *)0x0);
LAB_0002b7d2:
  *(undefined *)((int)arg + 0x124) = 0;
  return (void *)0x0;
}

