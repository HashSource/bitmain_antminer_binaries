
void _mutex_unlock_noyield(pthread_mutex_t *lock,char *file,char *func,int line)

{
  int *piVar1;
  char tmp42 [2048];
  
  piVar1 = __errno_location();
  snprintf(tmp42,0x800,DAT_0000a89c,*piVar1,DAT_0000a898,lock,file);
  _applog(3,tmp42,true);
  _quit(1);
  return;
}

