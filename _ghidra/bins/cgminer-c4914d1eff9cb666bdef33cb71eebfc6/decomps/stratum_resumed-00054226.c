
void stratum_resumed(pool *pool)

{
  _Bool _Var1;
  pool *pool_local;
  char tmp42 [2048];
  
  _Var1 = pool_tclear(pool,&pool->idle);
  if (_Var1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      snprintf(tmp42,0x800,"Stratum connection to pool %d resumed",pool->pool_no);
      _applog(6,tmp42,false);
    }
    pool_resus(pool);
  }
  return;
}

