
void _mutex_init(pthread_mutex_t *lock,char *file,char *func,int line)

{
  int *piVar1;
  char tmp42 [2048];
  
  piVar1 = __errno_location();
  snprintf(tmp42,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",*piVar1,
           "driver-btm-c5.c","bitmain_c5_prepare",lock);
  _applog(3,tmp42,true);
  _quit(1);
  return;
}

