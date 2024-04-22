
void _mutex_init(pthread_mutex_t *lock,char *file,char *func,int line)

{
  int iVar1;
  int *piVar2;
  int line_local;
  char *func_local;
  char *file_local;
  pthread_mutex_t *lock_local;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_init((pthread_mutex_t *)lock,(pthread_mutexattr_t *)0x0);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",*piVar2,file,func,
             line);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

