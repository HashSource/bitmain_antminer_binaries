
void bitmain_c5_update(int param_1)

{
  int iVar1;
  int *piVar2;
  pthread_mutex_t *__mutex;
  undefined4 *puVar3;
  undefined4 local_830;
  void *local_82c;
  char local_828 [2052];
  
  __mutex = *(pthread_mutex_t **)(param_1 + 0x14);
  puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 0x98);
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)((int)__mutex + 0x2a4));
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x4236);
    _applog(3,local_828,1);
    _quit(1);
  }
  *(undefined1 *)((int)puVar3 + 0x3f) = 0;
  *(undefined1 *)((int)puVar3 + 0x3e) = 0;
  local_82c = (void *)0x0;
  local_830 = get_work(puVar3,*puVar3);
  _discard_work(&local_830,"driver-btm-c5.c","bitmain_c5_update",0x423e);
  puVar3 = (undefined4 *)current_pool();
  if (*(char *)(puVar3 + 0xa0) == '\0') {
    builtin_strncpy(local_828,"Bitmain S9 has to use stratum pools",0x24);
    _applog(3,local_828,1);
    _quit(1);
    iVar1 = pthread_mutex_lock(__mutex);
  }
  else {
    iVar1 = pthread_mutex_lock(__mutex);
  }
  if (iVar1 == 0) {
    iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(__mutex + 1));
  }
  else {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x4245);
    _applog(3,local_828,1);
    _quit(1);
    iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)(__mutex + 1));
  }
  if (iVar1 == 0) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)(puVar3 + 0x35));
  }
  else {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x4245);
    _applog(3,local_828,1);
    _quit(1);
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)(puVar3 + 0x35));
  }
  if (iVar1 == 0) {
    iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)(puVar3 + 0x3b));
  }
  else {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x4246);
    _applog(3,local_828,1);
    _quit(1);
    iVar1 = pthread_rwlock_rdlock((pthread_rwlock_t *)(puVar3 + 0x3b));
  }
  if (iVar1 == 0) {
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(puVar3 + 0x35));
  }
  else {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x4246);
    _applog(3,local_828,1);
    _quit(1);
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)(puVar3 + 0x35));
  }
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x4246);
    _applog(3,local_828,1);
    _quit(1);
  }
  *(undefined4 *)((int)__mutex + 0x2dc) = *puVar3;
  copy_pool_stratum((int)__mutex + 0x1150,(int)__mutex + 0xa18);
  __mutex[0x106].__data.__lock = *(int *)((int)__mutex + 0x188c);
  copy_pool_stratum((int)__mutex + 0xa18,(int)__mutex + 0x2e0);
  *(undefined4 *)((int)__mutex + 0x188c) = *(undefined4 *)((int)__mutex + 0x1888);
  copy_pool_stratum((int)__mutex + 0x2e0,puVar3);
  given_id = given_id + 1;
  *(int *)((int)__mutex + 0x1888) = given_id;
  parse_job_to_c5(&local_82c,puVar3,given_id);
  if (status_error == '\0') {
    pthread_mutex_lock((pthread_mutex_t *)reinit_mutex);
    send_job(local_82c);
    pthread_mutex_unlock((pthread_mutex_t *)reinit_mutex);
  }
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(puVar3 + 0x3b));
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x4258);
    _applog(3,local_828,1);
    _quit(1);
  }
  (*selective_yield)();
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(__mutex + 1));
  if (iVar1 == 0) {
    iVar1 = pthread_mutex_unlock(__mutex);
  }
  else {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x4259);
    _applog(3,local_828,1);
    _quit(1);
    iVar1 = pthread_mutex_unlock(__mutex);
  }
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x4259);
    _applog(3,local_828,1);
    _quit(1);
  }
  (*selective_yield)();
  free(local_82c);
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)((int)__mutex + 0x2a4));
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,
             "driver-btm-c5.c","bitmain_c5_update",0x425b);
    _applog(3,local_828,1);
    _quit(1);
    (*selective_yield)();
    return;
  }
  (*selective_yield)();
  return;
}

