
/* WARNING: Unknown calling convention */

void switchpool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  long paramid;
  int iVar1;
  int iVar2;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int extraout_r3;
  pool *selected;
  int id;
  
  if (total_pools == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
    return;
  }
  if ((param != (char *)0x0) && (*param != '\0')) {
    paramid = strtol(param,(char **)0x0,10);
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)&control_lock);
    iVar2 = line;
    if (iVar1 != 0) {
      _mutex_lock((pthread_mutex_t *)"switchpool",(char *)0xb63,func,line);
      iVar2 = extraout_r3;
    }
    _rd_lock(&control_lock.rwlock,"switchpool",(char *)0xb63,iVar2);
    iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&control_lock);
    if (iVar2 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"switchpool",(char *)0xb63,func_00,line_00);
    }
    if ((-1 < paramid) && (paramid < total_pools)) {
      selected = pools[paramid];
      selected->enabled = POOL_ENABLED;
      iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&control_lock.rwlock);
      if (iVar2 != 0) {
        _rw_unlock((pthread_rwlock_t *)"switchpool",(char *)0xb6d,func_02,line_02);
      }
      (*selective_yield)();
      switch_pools(selected);
      message(io_data,0x1b,paramid,(char *)0x0,isjson);
      return;
    }
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)&control_lock.rwlock);
    if (iVar2 != 0) {
      _rw_unlock((pthread_rwlock_t *)"switchpool",(char *)0xb66,func_01,line_01);
    }
    (*selective_yield)();
    message(io_data,0x1a,paramid,(char *)0x0,isjson);
    return;
  }
  message(io_data,0x19,0,(char *)0x0,isjson);
  return;
}

