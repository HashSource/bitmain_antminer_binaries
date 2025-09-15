
void _wr_lock(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int iVar1;
  int *piVar2;
  char tmp42 [2048];
  
  iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)lock);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar2,"util.c",file,
             func);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

