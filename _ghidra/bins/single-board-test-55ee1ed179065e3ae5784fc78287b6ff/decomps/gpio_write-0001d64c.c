
undefined4 gpio_write(undefined4 param_1,char param_2)

{
  int iVar1;
  ssize_t sVar2;
  undefined4 uVar3;
  char acStack_4c [64];
  int local_c;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)api_mutex);
  if (iVar1 == 0) {
    snprintf(acStack_4c,0x40,"/sys/class/gpio/gpio%d/value",param_1);
    local_c = open(acStack_4c,1);
    if (local_c < 0) {
      printf("%s:%d","gpio_write",0x15c);
      puts("Failed to open gpio value for writing!");
      pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
      uVar3 = 0xfffffffe;
    }
    else {
      sVar2 = write(local_c,(void *)((int)&values_str_6753 + (uint)(param_2 != '\0')),1);
      if (sVar2 < 0) {
        printf("%s:%d","gpio_write",0x162);
        puts("Failed to write value!");
        close(local_c);
        pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
        uVar3 = 0xfffffffd;
      }
      else {
        close(local_c);
        pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
        uVar3 = 0;
      }
    }
  }
  else {
    printf("%s:%d","gpio_write",0x155);
    puts("failed to api lock");
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

