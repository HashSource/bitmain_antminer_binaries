
void _mutex_unlock_noyield(pthread_mutex_t *lock,char *file,char *func,int line)

{
  int iVar1;
  int *piVar2;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_unlock(DAT_0000f71c);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,DAT_0000f728,*piVar2,DAT_0000f720,DAT_0000f724,lock);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

