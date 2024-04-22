
_Bool pool_unusable(pool *pool)

{
  _Bool _Var1;
  pool *pool_local;
  
  if (pool->idle == false) {
    if (pool->enabled == POOL_ENABLED) {
      if ((pool->has_stratum == false) ||
         ((pool->stratum_active == true && (pool->stratum_notify == true)))) {
        _Var1 = false;
      }
      else {
        _Var1 = true;
      }
    }
    else {
      _Var1 = true;
    }
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}

