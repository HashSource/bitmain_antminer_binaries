
/* WARNING: Unknown calling convention */

_Bool pool_tset(pool *pool,_Bool *var)

{
  _Bool _Var1;
  int iVar2;
  char *func;
  char *func_00;
  int line;
  int line_00;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&pool->pool_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"pool_tset",(char *)0x305,func,line);
  }
  _Var1 = *var;
  *var = true;
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&pool->pool_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"pool_tset",(char *)0x30a,func_00,line_00);
  }
  (*selective_yield)();
  return _Var1;
}

