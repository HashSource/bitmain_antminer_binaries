
void _cg_wlock(cglock_t *lock,char *file,char *func,int line)

{
  int line_local;
  char *func_local;
  char *file_local;
  cglock_t *lock_local;
  
  _mutex_lock(&lock->mutex,file,func,line);
  _wr_lock(&lock->rwlock,file,func,line);
  return;
}

