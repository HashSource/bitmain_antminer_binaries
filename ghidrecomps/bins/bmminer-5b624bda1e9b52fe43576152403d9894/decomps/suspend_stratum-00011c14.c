
/* WARNING: Unknown calling convention */

void suspend_stratum(pool *pool)

{
  int iVar1;
  int *piVar2;
  char *in_r2;
  int iVar3;
  char tmp42 [2048];
  
  if (((*DAT_00011cd0 != '\0') || (*DAT_00011cd4 != '\0')) || (iVar3 = *DAT_00011ce0, 5 < iVar3)) {
    iVar3 = pool->pool_no;
    snprintf(tmp42,0x800,DAT_00011cd8);
    in_r2 = (char *)0x0;
    _applog(6,tmp42,false);
  }
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar1 != 0) {
    _mutex_lock(DAT_00011ce4,(char *)0xb9a,in_r2,iVar3);
  }
  clear_sockbuf(pool);
  pool->stratum_notify = false;
  pool->stratum_active = false;
  if (pool->sock != 0) {
    close(pool->sock);
  }
  pool->sock = 0;
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar3 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,DAT_00011cec,*piVar2,DAT_00011ce8,DAT_00011ce4,0xb9c);
    _applog(3,tmp42,true);
    _quit(1);
  }
  (**DAT_00011cdc)();
  return;
}

