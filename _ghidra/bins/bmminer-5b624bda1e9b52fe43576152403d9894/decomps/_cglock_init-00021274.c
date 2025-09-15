
void _cglock_init(cglock_t *lock,char *file,char *func,int line)

{
  int iVar1;
  char *func_00;
  char *func_01;
  int line_00;
  int line_01;
  
  iVar1 = pthread_mutex_init((pthread_mutex_t *)lock,(pthread_mutexattr_t *)0x0);
  if (iVar1 != 0) {
    _mutex_init((pthread_mutex_t *)file,func,func_00,line_00);
  }
  iVar1 = pthread_rwlock_init((pthread_rwlock_t *)&lock->rwlock,(pthread_rwlockattr_t *)0x0);
  if (iVar1 == 0) {
    return;
  }
  _rwlock_init((pthread_rwlock_t *)file,func,func_01,line_01);
  return;
}

