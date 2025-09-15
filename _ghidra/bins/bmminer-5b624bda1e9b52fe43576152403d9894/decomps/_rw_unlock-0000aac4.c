
void _rw_unlock(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int *piVar1;
  char tmp42 [2048];
  
  piVar1 = __errno_location();
  snprintf(tmp42,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar1,"cgminer.c",lock
           ,file);
  _applog(3,tmp42,true);
  _quit(1);
  return;
}

