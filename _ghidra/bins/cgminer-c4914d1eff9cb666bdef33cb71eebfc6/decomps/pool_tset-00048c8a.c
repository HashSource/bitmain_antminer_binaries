
_Bool pool_tset(pool *pool,_Bool *var)

{
  _Bool _Var1;
  _Bool *var_local;
  pool *pool_local;
  _Bool ret;
  
  _mutex_lock(&pool->pool_lock,"cgminer.c","pool_tset",0x313);
  _Var1 = *var;
  *var = true;
  _mutex_unlock(&pool->pool_lock,"cgminer.c","pool_tset",0x318);
  return _Var1;
}

