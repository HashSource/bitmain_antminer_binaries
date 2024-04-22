
void _rw_unlock(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int iVar1;
  int *piVar2;
  char tmp42 [2048];
  
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)lock);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,DAT_00010bf4,*piVar2,DAT_00010bf0,file,func);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

