
/* WARNING: Unknown calling convention */

void * test_pool_thread(void *arg)

{
  _Bool _Var1;
  pool *pool;
  int iVar2;
  int iVar3;
  pthread_t __th;
  char *in_r2;
  char *func;
  uint line;
  int iVar4;
  char tmp42 [2048];
  
  if (*(char *)((int)arg + 0x6b) == '\0') {
    __th = pthread_self();
    pthread_detach(__th);
  }
  while( true ) {
    line = (uint)*(byte *)((int)arg + 0x69);
    if (line != 0) {
      return (void *)0x0;
    }
    _Var1 = pool_active((pool *)arg,false);
    if (_Var1) break;
    pool_died((pool *)arg);
    if (*(char *)((int)arg + 0x6b) != '\0') goto LAB_00025fec;
    sleep(0x1e);
  }
  pool_tclear((pool *)arg,(_Bool *)((int)arg + 0x61));
  iVar2 = pthread_mutex_lock(DAT_00026064);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_00026074,(char *)0x2982,in_r2,line);
  }
  iVar2 = pthread_rwlock_wrlock(DAT_00026068);
  if (iVar2 != 0) {
    _wr_lock(DAT_00026074,(char *)0x2982,in_r2,line);
  }
  iVar2 = DAT_0002606c;
  iVar4 = 0;
  func = (char *)(uint)*(byte *)(DAT_0002606c + 0x74c);
  if (func == (char *)0x0) {
                    /* WARNING: Load size is inaccurate */
    iVar4 = *arg;
    func = (char *)0x1;
    *(void **)(DAT_0002606c + 0x498) = arg;
    *(undefined *)(iVar2 + 0x74c) = 1;
    if (iVar4 != 0) {
      iVar4 = 1;
    }
  }
  iVar3 = pthread_rwlock_unlock(DAT_00026068);
  if (iVar3 != 0) {
    _rw_unlock(DAT_00026074,(char *)0x2990,func,iVar2);
  }
  iVar3 = pthread_mutex_unlock(DAT_00026064);
  if (iVar3 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_00026074,(char *)0x2990,func,iVar2);
  }
  (**DAT_00026070)();
  if ((iVar4 != 0) && (((*DAT_00026078 != '\0' || (*DAT_0002607c != '\0')) || (4 < *DAT_00026080))))
  {
                    /* WARNING: Load size is inaccurate */
    snprintf(tmp42,0x800,DAT_00026084,*arg,*(undefined4 *)((int)arg + 0xa4));
    _applog(5,tmp42,false);
  }
  pool_resus((pool *)arg);
  switch_pools((pool *)0x0);
LAB_00025fec:
  *(undefined *)((int)arg + 0x11c) = 0;
  return (void *)0x0;
}

