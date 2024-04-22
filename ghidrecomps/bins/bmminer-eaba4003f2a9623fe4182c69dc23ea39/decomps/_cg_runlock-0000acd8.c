
void _cg_runlock(cglock_t *lock,char *file,char *func,int line)

{
  int line_local;
  char *func_local;
  char *file_local;
  cglock_t *lock_local;
  
  _rd_unlock(&lock->rwlock,file,func,line);
  return;
}

