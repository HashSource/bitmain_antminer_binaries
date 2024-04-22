
void _rw_unlock(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int iVar1;
  int *piVar2;
  int line_local;
  char *func_local;
  char *file_local;
  pthread_rwlock_t *lock_local;
  char tmp42 [2048];
  
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)lock);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,file,func,line
            );
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

