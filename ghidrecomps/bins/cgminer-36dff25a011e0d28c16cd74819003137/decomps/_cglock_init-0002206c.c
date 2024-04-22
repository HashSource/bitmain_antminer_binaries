
void _cglock_init(cglock_t *lock,char *file,char *func,int line)

{
  int line_local;
  char *func_local;
  char *file_local;
  cglock_t *lock_local;
  
  _mutex_init(&lock->mutex,file,func,line);
  _rwlock_init(&lock->rwlock,file,func,line);
  return;
}

