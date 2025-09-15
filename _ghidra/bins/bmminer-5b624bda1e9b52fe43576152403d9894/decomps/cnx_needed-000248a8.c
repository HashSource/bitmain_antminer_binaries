
/* WARNING: Unknown calling convention */

_Bool cnx_needed(pool *pool)

{
  pool *ppVar1;
  int iVar2;
  int iVar3;
  
  if (pool->enabled != POOL_ENABLED) {
    return false;
  }
  if (((((pool_strategy != POOL_BALANCE) && (pool_strategy != POOL_LOADBALANCE)) &&
       ((pool->has_stratum == false || (pool->idle == false)))) &&
      ((ppVar1 = current_pool(), pool != ppVar1 && (pool->sshares == 0)))) &&
     ((pool_strategy != POOL_FAILOVER || (iVar3 = pool->prio, iVar2 = cp_prio(), iVar2 <= iVar3))))
  {
    return no_work;
  }
  return true;
}

