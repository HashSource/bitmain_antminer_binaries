
void _mutex_lock(pthread_mutex_t *lock,char *file,char *func,int line)

{
  int iVar1;
  int *piVar2;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock(DAT_0000f774);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,DAT_0000f780,*piVar2,DAT_0000f778,DAT_0000f77c,0x31);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

