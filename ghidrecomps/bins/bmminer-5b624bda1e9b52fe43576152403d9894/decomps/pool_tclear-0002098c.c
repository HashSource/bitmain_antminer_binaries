
/* WARNING: Unknown calling convention */

_Bool pool_tclear(pool *pool,_Bool *var)

{
  _Bool _Var1;
  int iVar2;
  char *in_r2;
  int in_r3;
  int line;
  _Bool *ret;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&pool->pool_lock);
  if (iVar2 != 0) {
    _mutex_lock(DAT_000209d0,(char *)0x314,in_r2,in_r3);
  }
  line = 0;
  _Var1 = *var;
  *var = false;
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&pool->pool_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield(DAT_000209d0,(char *)0x319,in_r2,line);
  }
  (**DAT_000209cc)();
  return _Var1;
}

