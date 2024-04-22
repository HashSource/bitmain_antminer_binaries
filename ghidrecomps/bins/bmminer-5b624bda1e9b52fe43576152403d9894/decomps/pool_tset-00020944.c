
/* WARNING: Unknown calling convention */

_Bool pool_tset(pool *pool,_Bool *var)

{
  _Bool _Var1;
  int iVar2;
  char *in_r2;
  int in_r3;
  int line;
  _Bool *ret;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&pool->pool_lock);
  if (iVar2 != 0) {
    _mutex_lock(DAT_00020988,(char *)0x305,in_r2,in_r3);
  }
  line = 1;
  _Var1 = *var;
  *var = true;
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&pool->pool_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield(DAT_00020988,(char *)0x30a,in_r2,line);
  }
  (**DAT_00020984)();
  return _Var1;
}

