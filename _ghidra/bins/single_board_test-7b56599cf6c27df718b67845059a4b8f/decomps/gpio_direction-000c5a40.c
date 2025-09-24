
/* WARNING: Unknown calling convention */

int32_t gpio_direction(uint32_t port,bitmain_gpio_direction_e direction)

{
  int iVar1;
  ssize_t sVar2;
  int iVar3;
  int8_t path [64];
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&api_mutex);
  if (iVar1 != 0) {
    builtin_strncpy(tmp42,"failed to api lock\n",0x14);
    _applog(0,tmp42,false);
    return -1;
  }
  snprintf(path,0x40,"/sys/class/gpio/gpio%d/direction",port);
  iVar1 = open(path,1);
  if (iVar1 < 0) {
    snprintf(tmp42,0x800,"Failed to open gpio %d direction for writing!\n",port);
    _applog(0,tmp42,false);
    pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
    return -2;
  }
  if (direction == DIRECTION_IN) {
    sVar2 = write(iVar1,"in",2);
    iVar3 = 0;
    if (sVar2 < 0) goto LAB_000c5aa8;
  }
  else {
    sVar2 = write(iVar1,"out",3);
    if (sVar2 < 0) {
      iVar3 = 3;
LAB_000c5aa8:
      snprintf(tmp42,0x800,"Failed to set gpio %d direction %s !\n",port,"in" + iVar3);
      _applog(0,tmp42,false);
      close(iVar1);
      pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
      return -3;
    }
  }
  close(iVar1);
  pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
  return 0;
}

