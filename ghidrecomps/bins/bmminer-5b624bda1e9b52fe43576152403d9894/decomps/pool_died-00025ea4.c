
/* WARNING: Unknown calling convention */

void pool_died(pool *pool)

{
  _Bool _Var1;
  pool *ppVar2;
  char tmp42 [2048];
  
  _Var1 = pool_tset(pool,&pool->idle);
  if (!_Var1) {
    cgtime(&pool->tv_idle);
    ppVar2 = current_pool();
    if (ppVar2 == pool) {
      if (((*DAT_00025f3c != '\0') || (*DAT_00025f40 != '\0')) || (3 < *DAT_00025f48)) {
        snprintf(tmp42,0x800,DAT_00025f4c,ppVar2->pool_no,ppVar2->rpc_url);
        _applog(4,tmp42,false);
      }
      switch_pools((pool *)0x0);
    }
    else if (((*DAT_00025f3c != '\0') || (*DAT_00025f40 != '\0')) || (5 < *DAT_00025f48)) {
      snprintf(tmp42,0x800,DAT_00025f44,pool->pool_no,pool->rpc_url);
      _applog(6,tmp42,false);
    }
  }
  return;
}

