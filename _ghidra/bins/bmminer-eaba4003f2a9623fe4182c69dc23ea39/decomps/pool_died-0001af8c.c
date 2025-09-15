
void pool_died(pool *pool)

{
  _Bool _Var1;
  pool *ppVar2;
  pool *pool_local;
  char tmp42 [2048];
  
  _Var1 = pool_tset(pool,&pool->idle);
  if (!_Var1) {
    cgtime(&pool->tv_idle);
    ppVar2 = current_pool();
    if (ppVar2 == pool) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d %s not responding!",pool->pool_no,pool->rpc_url);
        _applog(4,tmp42,false);
      }
      switch_pools((pool *)0x0);
    }
    else if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      snprintf(tmp42,0x800,"Pool %d %s failed to return work",pool->pool_no,pool->rpc_url);
      _applog(6,tmp42,false);
    }
  }
  return;
}

