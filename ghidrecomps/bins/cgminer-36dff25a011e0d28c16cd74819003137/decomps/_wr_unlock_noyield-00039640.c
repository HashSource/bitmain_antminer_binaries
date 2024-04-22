
void _wr_unlock_noyield(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int line_local;
  char *func_local;
  char *file_local;
  pthread_rwlock_t *lock_local;
  
  _rw_unlock(lock,file,func,line);
  return;
}

