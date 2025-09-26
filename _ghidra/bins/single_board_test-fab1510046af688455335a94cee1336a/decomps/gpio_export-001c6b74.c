
/* WARNING: Unknown calling convention */

int32_t gpio_export(uint32_t port)

{
  int iVar1;
  size_t __n;
  ssize_t sVar2;
  int8_t buffer [64];
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&api_mutex);
  if (iVar1 != 0) {
    builtin_strncpy(tmp42,"failed to api lock\n",0x14);
    _applog(0,tmp42,false);
    return -1;
  }
  snprintf(buffer,0x40,"/sys/class/gpio/gpio%d",port);
  iVar1 = access(buffer,0);
  if (iVar1 != 0) {
    iVar1 = open("/sys/class/gpio/export",1);
    if (iVar1 < 0) {
      builtin_strncpy(tmp42,"Failed to open export for writing!\n",0x24);
      _applog(0,tmp42,false);
      pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
      return -2;
    }
    __n = snprintf(buffer,0x40,"%d",port);
    sVar2 = write(iVar1,buffer,__n);
    if (sVar2 < 0) {
      snprintf(tmp42,0x800,"Failed to export gpio %d!",port);
      _applog(0,tmp42,false);
      close(iVar1);
      pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
      return -3;
    }
    close(iVar1);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
  return 0;
}

