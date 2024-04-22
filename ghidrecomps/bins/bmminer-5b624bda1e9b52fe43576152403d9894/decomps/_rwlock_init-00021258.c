
void _rwlock_init(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int iVar1;
  char *func_00;
  
  func_00 = func;
  iVar1 = pthread_rwlock_init((pthread_rwlock_t *)lock,(pthread_rwlockattr_t *)0x0);
  if (iVar1 == 0) {
    return;
  }
  _rwlock_init((pthread_rwlock_t *)file,func,func_00,line);
  return;
}

