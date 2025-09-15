
/* WARNING: Unknown calling convention */

pool * select_pool(void)

{
  bool bVar1;
  _Bool _Var2;
  pool *cp_00;
  pool *pool_00;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
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
        iVar6 = total_pools;
        if (total_pools <= tested) {
          iVar6 = 0;
        }
        cVar3 = (char)iVar6;
        if (tested < total_pools) {
          cVar3 = '\x01';
        }
        tested = tested + 1;
        if (cVar3 == '\0') break;
        pool = pools[select_pool::rotating_pool];
        iVar5 = pool->quota_used;
        iVar4 = pool->quota_gcd;
        iVar6 = iVar4;
        if (iVar4 <= iVar5) {
          iVar6 = 0;
        }
        cVar3 = (char)iVar6;
        if (iVar5 < iVar4) {
          cVar3 = '\x01';
        }
        pool->quota_used = iVar5 + 1;
        if ((cVar3 != '\0') && (_Var2 = pool_unusable(pool), !_Var2)) break;
        select_pool::rotating_pool = select_pool::rotating_pool + 1;
        if (total_pools <= select_pool::rotating_pool) {
          select_pool::rotating_pool = 0;
        }
      }
      pool_00 = pool;
      if (pool == (pool *)0x0) {
        for (i = 0; pool_00 = pool, i < total_pools; i = i + 1) {
          pool_00 = priority_pool(i);
          _Var2 = pool_unusable(pool_00);
          if (!_Var2) break;
        }
      }
      pool = pool_00;
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

