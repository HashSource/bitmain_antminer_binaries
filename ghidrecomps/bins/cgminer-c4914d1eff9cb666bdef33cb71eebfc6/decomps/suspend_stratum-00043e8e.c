
void suspend_stratum(pool *pool)

{
  pool *pool_local;
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (5 < opt_log_level)) {
    snprintf(tmp42,0x800,"Closing socket for stratum pool %d",pool->pool_no);
    _applog(6,tmp42,false);
  }
  _mutex_lock(&pool->stratum_lock,"util.c","suspend_stratum",0xc54);
  __suspend_stratum(pool);
  _mutex_unlock(&pool->stratum_lock,"util.c","suspend_stratum",0xc56);
  return;
}

