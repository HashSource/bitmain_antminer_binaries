
_Bool pool_tclear(pool *pool,_Bool *var)

{
  _Bool _Var1;
  _Bool *var_local;
  pool *pool_local;
  _Bool ret;
  
  _mutex_lock(&pool->pool_lock,"cgminer.c","pool_tclear",0x31b);
  _Var1 = *var;
  *var = false;
  _mutex_unlock(&pool->pool_lock,"cgminer.c","pool_tclear",800);
  return _Var1;
}

