
/* WARNING: Unknown calling convention */

int32_t is_gpio_exist(uint32_t port)

{
  int iVar1;
  int32_t iVar2;
  int8_t buffer [64];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&api_mutex);
  if (iVar1 == 0) {
    snprintf(buffer,0x40,"/sys/class/gpio/gpio%d",port);
    iVar1 = access(buffer,0);
    if (iVar1 == 0) {
      pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
      return 1;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&api_mutex);
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
    builtin_memcpy(buffer,"failed to api lock\n",0x14);
    _applog(0,buffer,false);
  }
  return iVar2;
}

