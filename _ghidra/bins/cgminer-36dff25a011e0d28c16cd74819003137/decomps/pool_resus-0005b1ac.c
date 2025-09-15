
void pool_resus(pool *pool)

{
  int iVar1;
  int iVar2;
  pool *pool_local;
  char tmp42 [2048];
  
  pool->seq_getfails = 0;
  if ((pool_strategy == POOL_FAILOVER) && (iVar2 = pool->prio, iVar1 = cp_prio(), iVar2 < iVar1)) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Pool %d %s alive, testing stability",pool->pool_no,pool->rpc_url);
      _applog(4,tmp42,false);
    }
  }
  else if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Pool %d %s alive",pool->pool_no,pool->rpc_url);
    _applog(6,tmp42,false);
  }
  return;
}

