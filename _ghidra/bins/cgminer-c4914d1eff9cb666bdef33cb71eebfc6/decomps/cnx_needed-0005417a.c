
_Bool cnx_needed(pool *pool)

{
  pool *ppVar1;
  int iVar2;
  _Bool _Var3;
  int iVar4;
  pool *pool_local;
  pool *cp;
  
  if (pool->enabled == POOL_ENABLED) {
    if (pool_strategy == POOL_BALANCE) {
      _Var3 = true;
    }
    else if (pool_strategy == POOL_LOADBALANCE) {
      _Var3 = true;
    }
    else if ((pool->has_stratum == false) || (pool->idle == false)) {
      ppVar1 = current_pool();
      if (ppVar1 == pool) {
        _Var3 = true;
      }
      else if (pool->sshares == 0) {
        if ((pool_strategy == POOL_FAILOVER) &&
           (iVar4 = pool->prio, iVar2 = cp_prio(), iVar4 < iVar2)) {
          _Var3 = true;
        }
        else if (no_work == false) {
          _Var3 = false;
        }
        else {
          _Var3 = true;
        }
      }
      else {
        _Var3 = true;
      }
    }
    else {
      _Var3 = true;
    }
  }
  else {
    _Var3 = false;
  }
  return _Var3;
}

