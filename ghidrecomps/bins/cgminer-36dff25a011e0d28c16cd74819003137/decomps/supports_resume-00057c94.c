
_Bool supports_resume(pool *pool)

{
  undefined uVar1;
  char *pcVar2;
  bool bVar3;
  pool *pool_local;
  _Bool ret;
  
  _cg_rlock(&pool->data_lock,"cgminer.c","supports_resume",0x1d1c);
  pcVar2 = pool->sessionid;
  bVar3 = pcVar2 != (char *)0x0;
  if (bVar3) {
    pcVar2 = (char *)0x1;
  }
  uVar1 = SUB41(pcVar2,0);
  if (!bVar3) {
    uVar1 = 0;
  }
  _cg_runlock(&pool->data_lock,"cgminer.c","supports_resume",0x1d1e);
  return (_Bool)uVar1;
}

