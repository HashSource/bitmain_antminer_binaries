
pool * priority_pool(int choice)

{
  pool *ppVar1;
  int choice_local;
  char tmp42 [2048];
  pool *pool;
  int i;
  pool *ret;
  
  ret = (pool *)0x0;
  i = 0;
  while ((ppVar1 = ret, i < total_pools && (ppVar1 = pools[i], pools[i]->prio != choice))) {
    i = i + 1;
  }
  ret = ppVar1;
  if (ret == (pool *)0x0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"WTF No pool %d found!",choice);
      _applog(3,tmp42,false);
    }
    ret = pools[choice];
  }
  return ret;
}

