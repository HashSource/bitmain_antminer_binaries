
/* WARNING: Unknown calling convention */

void bitmain_c5_update(cgpu_info *bitmain_c5)

{
  int iVar1;
  pool *pool;
  int *piVar2;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  char *func_03;
  char *func_04;
  char *func_05;
  char *func_06;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  int line_04;
  int line_05;
  int line_06;
  bitmain_c5_info *info;
  pthread_mutex_t *__mutex;
  thr_info *thr;
  pthread_rwlock_t *__rwlock;
  work *local_830;
  uchar *local_82c;
  char tmp42 [2048];
  
  __mutex = (pthread_mutex_t *)bitmain_c5->device_data;
  thr = *bitmain_c5->thr;
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)((int)__mutex + 0x1a4));
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"bitmain_c5_update",(char *)0x2f07,func,line);
  }
  thr->work_update = false;
  thr->work_restart = false;
  local_82c = (uchar *)0x0;
  local_830 = get_work(thr,thr->id);
  _discard_work(&local_830,"driver-btm-c5.c","bitmain_c5_update",0x2f0f);
  pool = current_pool();
  if (pool->has_stratum == false) {
    builtin_strncpy(tmp42,"Bitmain S9 has to use stratum pools",0x24);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = pthread_mutex_lock(__mutex);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"bitmain_c5_update",(char *)0x2f16,func_00,line_00);
  }
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(__mutex + 1));
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x2f16);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"bitmain_c5_update",(char *)0x2f17,func_01,line_01);
  }
  __rwlock = &(pool->data_lock).rwlock;
  iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)__rwlock);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x2f17);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&pool->data_lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"bitmain_c5_update",(char *)0x2f17,func_02,line_02);
  }
  *(int *)((int)__mutex + 0x1dc) = pool->pool_no;
  copy_pool_stratum((pool *)&__mutex[0xae].__data,(pool *)&__mutex[0x61].__data);
  *(undefined4 *)((int)__mutex + 0x1790) = *(undefined4 *)((int)__mutex + 0x178c);
  copy_pool_stratum((pool *)&__mutex[0x61].__data,(pool *)&__mutex[0x14].__data);
  *(int *)((int)__mutex + 0x178c) = __mutex[0xfb].__data.__lock;
  copy_pool_stratum((pool *)&__mutex[0x14].__data,pool);
  given_id = given_id + 1;
  __mutex[0xfb].__data.__lock = given_id;
  parse_job_to_c5(&local_82c,pool,given_id);
  if (status_error == false) {
    pthread_mutex_lock((pthread_mutex_t *)&reinit_mutex);
    send_job(local_82c);
    pthread_mutex_unlock((pthread_mutex_t *)&reinit_mutex);
  }
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"bitmain_c5_update",(char *)0x2f29,func_03,line_03);
  }
  (*selective_yield)();
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(__mutex + 1));
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)"bitmain_c5_update",(char *)0x2f2a,func_04,line_04);
  }
  iVar1 = pthread_mutex_unlock(__mutex);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"bitmain_c5_update",(char *)0x2f2a,func_05,line_05);
  }
  (*selective_yield)();
  free(local_82c);
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)((int)__mutex + 0x1a4));
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"bitmain_c5_update",(char *)0x2f2c,func_06,line_06);
  }
  (*selective_yield)();
  return;
}

