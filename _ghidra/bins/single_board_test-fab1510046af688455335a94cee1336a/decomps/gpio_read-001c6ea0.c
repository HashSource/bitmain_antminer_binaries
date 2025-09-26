
/* WARNING: Unknown calling convention */

int32_t gpio_read(uint32_t port,uint8_t *val)

{
  int iVar1;
  ssize_t sVar2;
  long lVar3;
  int32_t iVar4;
  int8_t value [4];
  int8_t path [64];
  char tmp42 [2048];
  
  value[0] = '\0';
  value[1] = '\0';
  value[2] = '\0';
  value[3] = '\0';
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&api_mutex);
  if (iVar1 == 0) {
    snprintf(path,0x40,"/sys/class/gpio/gpio%d/value",port);
    iVar1 = open(path,0x800);
    if (iVar1 < 0) {
      snprintf(tmp42,0x800,"Failed to open gpio %d value for reading!\n",port);
      iVar4 = -2;
      _applog(0,tmp42,false);
      pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
    }
    else {
      sVar2 = read(iVar1,value,4);
      if (sVar2 < 0) {
        builtin_strncpy(tmp42,"Failed to read value",0x14);
        tmp42[0x14] = '!';
        tmp42[0x15] = '\n';
        tmp42[0x16] = '\0';
        iVar4 = -3;
        _applog(0,tmp42,false);
        close(iVar1);
        pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
      }
      else {
        close(iVar1);
        pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
        lVar3 = strtol(value,(char **)0x0,10);
        *val = (uint8_t)lVar3;
        iVar4 = 0;
      }
    }
  }
  else {
    iVar4 = -1;
    builtin_strncpy(tmp42,"failed to api lock\n",0x14);
    _applog(0,tmp42,false);
  }
  return iVar4;
}

