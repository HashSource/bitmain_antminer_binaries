
void _mutex_unlock(pthread_mutex_t *lock,char *file,char *func,int line)

{
  int iVar1;
  char *func_00;
  
  func_00 = func;
  iVar1 = pthread_mutex_unlock((pthread_mutex_t *)lock);
  if (iVar1 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)file,func,func_00,line);
  }
  (**DAT_0001943c)();
  return;
}

