
undefined4 gpio_direction(undefined4 param_1,int param_2)

{
  int iVar1;
  ssize_t sVar2;
  undefined4 uVar3;
  size_t __n;
  char acStack_4c [64];
  int local_c;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)api_mutex);
  if (iVar1 == 0) {
    snprintf(acStack_4c,0x40,"/sys/class/gpio/gpio%d/direction",param_1);
    local_c = open(acStack_4c,1);
    if (local_c < 0) {
      printf("%s:%d","gpio_direction",0x111);
      printf("Failed to open gpio %d direction for writing!\n",param_1);
      pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
      uVar3 = 0xfffffffe;
    }
    else {
      if (param_2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 3;
      }
      if (param_2 == 0) {
        __n = 2;
      }
      else {
        __n = 3;
      }
      sVar2 = write(local_c,(void *)((int)&dir_str_6737 + iVar1),__n);
      if (sVar2 < 0) {
        printf("%s:%d","gpio_direction",0x117);
        if (param_2 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = 3;
        }
        printf("Failed to set gpio %d direction %s !\n",param_1,(int)&dir_str_6737 + iVar1);
        close(local_c);
        pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
        uVar3 = 0xfffffffd;
      }
      else {
        printf("%s:%d","gpio_direction",0x11c);
        if (param_2 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = 3;
        }
        printf("set gpio %d direction %s success!\n",param_1,(int)&dir_str_6737 + iVar1);
        close(local_c);
        pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
        uVar3 = 0;
      }
    }
  }
  else {
    printf("%s:%d","gpio_direction",0x10a);
    puts("failed to api lock");
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

