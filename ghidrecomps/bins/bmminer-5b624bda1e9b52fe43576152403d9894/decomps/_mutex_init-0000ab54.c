
void _mutex_init(pthread_mutex_t *lock,char *file,char *func,int line)

{
  undefined4 uVar1;
  int *piVar2;
  char tmp42 [2048];
  
  uVar1 = DAT_0000ab94;
  piVar2 = __errno_location();
  snprintf(tmp42,0x800,DAT_0000ab9c,*piVar2,uVar1,DAT_0000ab98,lock);
  _applog(3,tmp42,true);
  _quit(1);
  return;
}

