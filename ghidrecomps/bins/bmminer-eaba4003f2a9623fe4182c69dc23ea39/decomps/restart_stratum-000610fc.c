
_Bool restart_stratum(pool *pool)

{
  _Bool _Var1;
  pool *pool_local;
  _Bool ret;
  
  ret = false;
  if (pool->stratum_active != false) {
    suspend_stratum(pool);
  }
  _Var1 = initiate_stratum(pool);
  if ((_Var1) &&
     (((pool->extranonce_subscribe == false || (_Var1 = subscribe_extranonce(pool), _Var1)) &&
      (_Var1 = auth_stratum(pool), _Var1)))) {
    ret = true;
  }
  if (ret == true) {
    stratum_resumed(pool);
  }
  else {
    pool_died(pool);
  }
  return ret;
}

