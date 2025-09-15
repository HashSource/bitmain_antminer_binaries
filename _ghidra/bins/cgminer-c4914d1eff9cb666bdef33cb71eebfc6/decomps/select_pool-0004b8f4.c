
/* WARNING: Unknown calling convention */

pool * select_pool(void)

{
  bool bVar1;
  _Bool _Var2;
  pool *cp_00;
  pool *ppVar3;
  int iVar4;
  int iVar5;
  char tmp42 [2048];
  pool *tp_1;
  pool *tp;
  pool *cp;
  int i;
  int tested;
  _Bool avail;
  pool *pool;
  
  bVar1 = false;
  cp_00 = current_pool();
  if (pool_strategy == POOL_BALANCE) {
    pool = select_balanced(cp_00);
  }
  else {
    pool = cp_00;
    if (pool_strategy == POOL_LOADBALANCE) {
      for (i = 0; i < total_pools; i = i + 1) {
        if (pools[i]->quota_used < pools[i]->quota_gcd) {
          bVar1 = true;
          break;
        }
      }
      if (!bVar1) {
        for (i = 0; i < total_pools; i = i + 1) {
          pools[i]->quota_used = 0;
        }
        select_pool::rotating_pool = select_pool::rotating_pool + 1;
        if (total_pools <= select_pool::rotating_pool) {
          select_pool::rotating_pool = 0;
        }
      }
      tested = 0;
      while( true ) {
        pool = (pool *)0x0;
        iVar5 = tested + 1;
        if (total_pools <= tested) break;
        pool = pools[select_pool::rotating_pool];
        iVar4 = pool->quota_used;
        pool->quota_used = iVar4 + 1;
        if (iVar4 < pool->quota_gcd) {
          _Var2 = pool_unusable(pool);
          if (!_Var2) break;
          if (opt_fail_only != false) {
            ppVar3 = priority_pool(0);
            ppVar3->quota_used = ppVar3->quota_used + -1;
          }
        }
        select_pool::rotating_pool = select_pool::rotating_pool + 1;
        tested = iVar5;
        if (total_pools <= select_pool::rotating_pool) {
          select_pool::rotating_pool = 0;
        }
      }
      ppVar3 = pool;
      if (pool == (pool *)0x0) {
        for (i = 0; ppVar3 = pool, i < total_pools; i = i + 1) {
          ppVar3 = priority_pool(i);
          _Var2 = pool_unusable(ppVar3);
          if (!_Var2) break;
        }
      }
      pool = ppVar3;
      if (pool == (pool *)0x0) {
        pool = cp_00;
      }
    }
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Selecting pool %d for work",pool->pool_no);
    _applog(7,tmp42,false);
  }
  return pool;
}

