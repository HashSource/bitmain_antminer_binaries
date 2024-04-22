
void _rd_unlock(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int iVar1;
  char *func_00;
  
  func_00 = func;
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)lock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)file,func,func_00,line);
  }
  (**DAT_00021790)();
  return;
}

