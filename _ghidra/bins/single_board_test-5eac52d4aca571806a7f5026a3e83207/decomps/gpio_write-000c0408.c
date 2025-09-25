
/* WARNING: Unknown calling convention */

int32_t gpio_write(uint32_t port,uint8_t val)

{
  int iVar1;
  ssize_t sVar2;
  int8_t *__buf;
  int32_t iVar3;
  int8_t path [64];
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&api_mutex);
  if (iVar1 == 0) {
    snprintf(path,0x40,"/sys/class/gpio/gpio%d/value",port);
    iVar1 = open(path,0x801);
    if (iVar1 < 0) {
      builtin_strncpy(tmp42,"Failed to open gpio value for writing!\n",0x28);
      iVar3 = -2;
      _applog(0,tmp42,false);
      pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
    }
    else {
      __buf = "01";
      if (val != '\0') {
        __buf = "1";
      }
      sVar2 = write(iVar1,__buf,1);
      if (sVar2 < 0) {
        builtin_strncpy(tmp42,"Failed to write value!\n",0x18);
        iVar3 = -3;
        _applog(0,tmp42,false);
        close(iVar1);
        pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
      }
      else {
        close(iVar1);
        pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
        iVar3 = 0;
      }
    }
  }
  else {
    iVar3 = -1;
    builtin_strncpy(tmp42,"failed to api lock\n",0x14);
    _applog(0,tmp42,false);
  }
  return iVar3;
}

