
void _cg_dwlock(cglock_t *lock,char *file,char *func,int line)

{
  int line_local;
  char *func_local;
  char *file_local;
  cglock_t *lock_local;
  
  _wr_unlock_noyield(&lock->rwlock,file,func,line);
  _rd_lock(&lock->rwlock,file,func,line);
  _mutex_unlock_noyield(&lock->mutex,file,func,line);
  return;
}

