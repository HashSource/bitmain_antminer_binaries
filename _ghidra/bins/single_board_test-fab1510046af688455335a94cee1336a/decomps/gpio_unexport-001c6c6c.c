
/* WARNING: Unknown calling convention */

int32_t gpio_unexport(uint32_t port)

{
  int iVar1;
  size_t __n;
  ssize_t sVar2;
  int32_t iVar3;
  int8_t buffer [64];
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&api_mutex);
  if (iVar1 == 0) {
    snprintf(buffer,0x40,"/sys/class/gpio/gpio%d",port);
    iVar1 = access(buffer,0);
    if (iVar1 != 0) {
      snprintf(tmp42,0x800,"port %d already unexported, ret = %d\n",port,iVar1);
      _applog(1,tmp42,false);
      perror("access error");
      pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
      return 0;
    }
    iVar1 = open("/sys/class/gpio/unexport",1);
    if (iVar1 < 0) {
      builtin_strncpy(tmp42,"Failed to open unexport for writing!",0x24);
      tmp42[0x24] = '\n';
      tmp42[0x25] = '\0';
      _applog(0,tmp42,false);
      iVar3 = -2;
      pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
    }
    else {
      __n = snprintf(buffer,0x40,"%d",port);
      sVar2 = write(iVar1,buffer,__n);
      if (sVar2 < 0) {
        snprintf(tmp42,0x800,"Failed to unexport gpio %d!",port);
        iVar3 = -2;
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

