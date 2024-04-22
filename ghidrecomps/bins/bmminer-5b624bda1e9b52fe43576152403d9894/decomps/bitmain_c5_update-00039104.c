
/* WARNING: Unknown calling convention */

void bitmain_c5_update(cgpu_info *bitmain_c5)

{
  code **ppcVar1;
  int iVar2;
  pool *pool_00;
  pool *pool;
  uint *puVar3;
  char *in_r2;
  pthread_rwlock_t *func;
  thr_info **line;
  uint uVar4;
  char *func_00;
  code *pcVar5;
  bitmain_c5_info *info;
  pthread_mutex_t *__mutex;
  thr_info *thr_00;
  thr_info *thr;
  pthread_rwlock_t *__rwlock;
  work *work;
  uchar *buf;
  char tmp42 [2048];
  
  __mutex = (pthread_mutex_t *)bitmain_c5->device_data;
  line = bitmain_c5->thr;
  thr_00 = *line;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)((int)__mutex + 0x1a4));
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_0003933c,(char *)0x2f07,in_r2,(int)line);
  }
  thr_00->work_update = false;
  thr_00->work_restart = false;
  buf = (uchar *)0x0;
  work = get_work(thr_00,thr_00->id);
  func = DAT_0003933c;
  _discard_work(&work,DAT_00039338,DAT_0003933c->__size,0x2f0f);
  pool_00 = current_pool();
  uVar4 = (uint)pool_00->has_stratum;
  if (uVar4 == 0) {
    tmp42._0_4_ = *DAT_0003934c;
    tmp42._4_4_ = DAT_0003934c[1];
    tmp42._8_4_ = DAT_0003934c[2];
    tmp42._12_4_ = DAT_0003934c[3];
    tmp42._16_4_ = DAT_0003934c[4];
    tmp42._20_4_ = DAT_0003934c[5];
    tmp42._24_4_ = DAT_0003934c[6];
    uVar4 = DAT_0003934c[7];
    tmp42._32_4_ = DAT_0003934c[8];
    func = (pthread_rwlock_t *)0x1;
    tmp42._28_4_ = uVar4;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar2 = pthread_mutex_lock(__mutex);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_0003933c,(char *)0x2f16,func->__size,uVar4);
  }
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(__mutex + 1));
  if (iVar2 != 0) {
    puVar3 = (uint *)__errno_location();
    uVar4 = *puVar3;
    snprintf(tmp42,0x800,DAT_00039354,uVar4,DAT_00039338,DAT_0003933c,0x2f16);
    func = (pthread_rwlock_t *)0x1;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&pool_00->data_lock);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_0003933c,(char *)0x2f17,func->__size,uVar4);
  }
  __rwlock = &(pool_00->data_lock).rwlock;
  iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)__rwlock);
  if (iVar2 != 0) {
    puVar3 = (uint *)__errno_location();
    uVar4 = *puVar3;
    snprintf(tmp42,0x800,DAT_00039350,uVar4,DAT_00039338,DAT_0003933c,0x2f17);
    func = (pthread_rwlock_t *)0x1;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)&pool_00->data_lock);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_0003933c,(char *)0x2f17,func->__size,uVar4);
  }
  *(int *)((int)__mutex + 0x1dc) = pool_00->pool_no;
  copy_pool_stratum((pool *)(__mutex + 0xae),(pool *)(__mutex + 0x61));
  *(undefined4 *)((int)__mutex + 0x1790) = *(undefined4 *)((int)__mutex + 0x178c);
  copy_pool_stratum((pool *)(__mutex + 0x61),(pool *)(__mutex + 0x14));
  *(int *)((int)__mutex + 0x178c) = __mutex[0xfb].__data.__lock;
  copy_pool_stratum((pool *)(__mutex + 0x14),pool_00);
  iVar2 = DAT_00039358;
  func_00 = (char *)(*(int *)(DAT_00039358 + 0x78) + 1);
  __mutex[0xfb].__data.__lock = (int)func_00;
  *(char **)(iVar2 + 0x78) = func_00;
  parse_job_to_c5(&buf,pool_00,(uint)func_00);
  uVar4 = (uint)*(byte *)(DAT_00039340 + 8);
  if (uVar4 == 0) {
    pthread_mutex_lock(DAT_00039344);
    send_job(buf);
    pthread_mutex_unlock(DAT_00039344);
  }
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
  if (iVar2 != 0) {
    _rw_unlock(DAT_0003933c,(char *)0x2f29,func_00,uVar4);
  }
  ppcVar1 = DAT_00039348;
  pcVar5 = *DAT_00039348;
  (*pcVar5)();
  iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(__mutex + 1));
  if (iVar2 != 0) {
    _rw_unlock(DAT_0003933c,(char *)0x2f2a,func_00,(int)pcVar5);
  }
  iVar2 = pthread_mutex_unlock(__mutex);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_0003933c,(char *)0x2f2a,func_00,(int)pcVar5);
  }
  pcVar5 = *ppcVar1;
  (*pcVar5)();
  free(buf);
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)((int)__mutex + 0x1a4));
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_0003933c,(char *)0x2f2c,func_00,(int)pcVar5);
  }
  (**ppcVar1)();
  return;
}

