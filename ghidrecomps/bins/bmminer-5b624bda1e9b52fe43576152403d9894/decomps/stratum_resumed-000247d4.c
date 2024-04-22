
/* WARNING: Unknown calling convention */

void stratum_resumed(pool *pool)

{
  _Bool _Var1;
  char tmp42 [2048];
  
  _Var1 = pool_tclear(pool,&pool->idle);
  if (_Var1) {
    if (((*DAT_00024820 != '\0') || (*DAT_00024824 != '\0')) || (5 < *DAT_00024828)) {
      snprintf(tmp42,0x800,DAT_0002482c,pool->pool_no);
      _applog(6,tmp42,false);
    }
    pool_resus(pool);
  }
  return;
}

