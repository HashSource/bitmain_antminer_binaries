
void pool_start_lp(pool *pool)

{
  int iVar1;
  pool *pool_local;
  char tmp42 [2048];
  
  if (pool->lp_started != true) {
    pool->lp_started = true;
    iVar1 = pthread_create(&pool->longpoll_thread,(pthread_attr_t *)0x0,(__start_routine *)0x294ad,
                           pool);
    if (iVar1 != 0) {
      builtin_strncpy(tmp42,"Failed to create pool longpoll threa",0x24);
      tmp42[0x24] = 'd';
      tmp42[0x25] = '\0';
      _applog(3,tmp42,true);
      _quit(1);
    }
  }
  return;
}

