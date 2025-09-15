
int _wr_trylock(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int iVar1;
  int line_local;
  char *func_local;
  char *file_local;
  pthread_rwlock_t *lock_local;
  int ret;
  
  iVar1 = pthread_rwlock_trywrlock((pthread_rwlock_t *)lock);
  return iVar1;
}

