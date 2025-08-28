
void init_stratum_threads(pool *pool)

{
  int iVar1;
  pool *pool_local;
  char tmp42 [2048];
  
  have_longpoll = true;
  iVar1 = pthread_create(&pool->stratum_sthread,(pthread_attr_t *)0x0,(__start_routine *)0x54739,
                         pool);
  if (iVar1 != 0) {
    builtin_strncpy(tmp42,"Failed to create stratum sthread",0x20);
    tmp42[0x20] = '\0';
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = pthread_create(&pool->stratum_rthread,(pthread_attr_t *)0x0,(__start_routine *)0x5430d,
                         pool);
  if (iVar1 != 0) {
    builtin_strncpy(tmp42,"Failed to create stratum rthread",0x20);
    tmp42[0x20] = '\0';
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

