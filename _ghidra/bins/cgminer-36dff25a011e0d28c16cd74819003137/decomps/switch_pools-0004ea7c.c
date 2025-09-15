
void switch_pools(pool *selected)

{
  pool *pool_00;
  _Bool _Var1;
  pool *ppVar2;
  pool *selected_local;
  char tmp42 [2048];
  pool *pool;
  pool *last_pool;
  int next_pool;
  int pool_no;
  int i;
  
  _cg_wlock(&control_lock,"cgminer.c","switch_pools",0x1465);
  pool_00 = currentpool;
  pool_no = currentpool->pool_no;
  if ((selected != (pool *)0x0) && (selected->prio != 0)) {
    for (i = 0; i < total_pools; i = i + 1) {
      ppVar2 = pools[i];
      if (ppVar2->prio < selected->prio) {
        ppVar2->prio = ppVar2->prio + 1;
      }
    }
    selected->prio = 0;
  }
  switch(pool_strategy) {
  case POOL_FAILOVER:
  case POOL_LOADBALANCE:
  case POOL_BALANCE:
    for (i = 0; i < total_pools; i = i + 1) {
      ppVar2 = priority_pool(i);
      _Var1 = pool_unusable(ppVar2);
      if (!_Var1) {
        pool_no = ppVar2->pool_no;
        break;
      }
    }
    break;
  case POOL_ROUNDROBIN:
  case POOL_ROTATE:
    if ((selected == (pool *)0x0) || (selected->idle == true)) {
      next_pool = pool_no;
      for (i = 1; i < total_pools; i = i + 1) {
        next_pool = next_pool + 1;
        if (total_pools <= next_pool) {
          next_pool = 0;
        }
        _Var1 = pool_unusable(pools[next_pool]);
        if (!_Var1) {
          pool_no = next_pool;
          break;
        }
      }
    }
    else {
      pool_no = selected->pool_no;
    }
  }
  ppVar2 = pools[pool_no];
  currentpool = ppVar2;
  _cg_wunlock(&control_lock,"cgminer.c","switch_pools",0x14b6);
  if (((ppVar2 != pool_00) && (pool_strategy != POOL_LOADBALANCE)) &&
     (pool_strategy != POOL_BALANCE)) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Switching to pool %d %s",ppVar2->pool_no,ppVar2->rpc_url);
      _applog(4,tmp42,false);
    }
    clear_pool_work(pool_00);
  }
  _mutex_lock(&lp_lock,"cgminer.c","switch_pools",0x14be);
  pthread_cond_broadcast((pthread_cond_t *)&lp_cond);
  _mutex_unlock(&lp_lock,"cgminer.c","switch_pools",0x14c0);
  return;
}

