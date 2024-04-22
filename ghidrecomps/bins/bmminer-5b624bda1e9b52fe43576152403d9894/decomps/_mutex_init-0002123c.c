
void _mutex_init(pthread_mutex_t *lock,char *file,char *func,int line)

{
  int iVar1;
  char *func_00;
  
  func_00 = func;
  iVar1 = pthread_mutex_init((pthread_mutex_t *)lock,(pthread_mutexattr_t *)0x0);
  if (iVar1 == 0) {
    return;
  }
  _mutex_init((pthread_mutex_t *)file,func,func_00,line);
  return;
}

