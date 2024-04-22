
int _mutex_trylock(pthread_mutex_t *lock,char *file,char *func,int line)

{
  int iVar1;
  int line_local;
  char *func_local;
  char *file_local;
  pthread_mutex_t *lock_local;
  int ret;
  
  iVar1 = pthread_mutex_trylock((pthread_mutex_t *)lock);
  return iVar1;
}

