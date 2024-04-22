
/* WARNING: Unknown calling convention */

_Bool restart_stratum(pool *pool)

{
  _Bool _Var1;
  
  if (pool->stratum_active != false) {
    suspend_stratum(pool);
  }
  _Var1 = initiate_stratum(pool);
  if ((_Var1) &&
     (((pool->extranonce_subscribe == false || (_Var1 = subscribe_extranonce(pool), _Var1)) &&
      (_Var1 = auth_stratum(pool), _Var1)))) {
    stratum_resumed(pool);
    return true;
  }
  pool_died(pool);
  return false;
}

