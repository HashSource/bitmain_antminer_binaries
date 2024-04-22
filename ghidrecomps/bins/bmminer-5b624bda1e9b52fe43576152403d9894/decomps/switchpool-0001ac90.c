
/* WARNING: Unknown calling convention */

void switchpool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  uint *puVar1;
  pthread_rwlock_t *__rwlock;
  long paramid;
  int iVar2;
  char *pcVar3;
  uint line;
  int line_00;
  pool *selected;
  pool *pool;
  int id;
  
  puVar1 = DAT_0001ad84;
  if (*DAT_0001ad84 == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
    return;
  }
  if ((param != (char *)0x0) && (line = (uint)(byte)*param, line != 0)) {
    pcVar3 = (char *)0xa;
    paramid = strtol(param,(char **)0x0,10);
    iVar2 = pthread_mutex_lock(DAT_0001ad88);
    if (iVar2 != 0) {
      _mutex_lock((pthread_mutex_t *)DAT_0001ad90,(char *)0xb63,pcVar3,line);
    }
    pcVar3 = (char *)0xb63;
    _rd_lock(DAT_0001ad8c,DAT_0001ad90->__size,(char *)0xb63,line);
    iVar2 = pthread_mutex_unlock(DAT_0001ad88);
    if (iVar2 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)DAT_0001ad90,(char *)0xb63,pcVar3,line);
    }
    __rwlock = (pthread_rwlock_t *)DAT_0001ad8c;
    if ((-1 < paramid) && (line = *puVar1, paramid < (int)line)) {
      line_00 = 1;
      pcVar3 = *DAT_0001ad98;
      selected = *(pool **)(pcVar3 + paramid * 4);
      selected->enabled = POOL_ENABLED;
      iVar2 = pthread_rwlock_unlock(__rwlock);
      if (iVar2 != 0) {
        _rw_unlock(DAT_0001ad90,(char *)0xb6d,pcVar3,line_00);
      }
      (**DAT_0001ad94)();
      switch_pools(selected);
      message(io_data,0x1b,paramid,(char *)0x0,isjson);
      return;
    }
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)DAT_0001ad8c);
    if (iVar2 != 0) {
      _rw_unlock(DAT_0001ad90,(char *)0xb66,pcVar3,line);
    }
    (**DAT_0001ad94)();
    message(io_data,0x1a,paramid,(char *)0x0,isjson);
    return;
  }
  message(io_data,0x19,0,(char *)0x0,isjson);
  return;
}

