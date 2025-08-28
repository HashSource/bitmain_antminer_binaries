
void _rd_unlock(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int iVar1;
  char *func_00;
  int line_00;
  
  iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)lock);
  if (iVar1 != 0) {
    _rw_unlock((pthread_rwlock_t *)file,func,func_00,line_00);
  }
  (*selective_yield)();
  return;
}

