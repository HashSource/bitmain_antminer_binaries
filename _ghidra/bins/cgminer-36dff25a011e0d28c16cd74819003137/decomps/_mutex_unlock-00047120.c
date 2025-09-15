
void _mutex_unlock(pthread_mutex_t *lock,char *file,char *func,int line)

{
  int line_local;
  char *func_local;
  char *file_local;
  pthread_mutex_t *lock_local;
  
  _mutex_unlock_noyield(lock,file,func,line);
  (*selective_yield)();
  return;
}

