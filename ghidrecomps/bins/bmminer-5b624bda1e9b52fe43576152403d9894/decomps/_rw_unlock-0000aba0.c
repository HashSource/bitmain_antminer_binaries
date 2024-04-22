
void _rw_unlock(pthread_rwlock_t *lock,char *file,char *func,int line)

{
  int *piVar1;
  char tmp42 [2048];
  
  piVar1 = __errno_location();
  snprintf(tmp42,0x800,DAT_0000abe4,*piVar1,DAT_0000abe0,lock,file);
  _applog(3,tmp42,true);
  _quit(1);
  return;
}

