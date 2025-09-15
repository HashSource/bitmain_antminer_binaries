
undefined4 gpio_export(undefined4 param_1)

{
  int iVar1;
  ssize_t sVar2;
  undefined4 uVar3;
  char acStack_50 [64];
  size_t local_10;
  int local_c;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)api_mutex);
  if (iVar1 == 0) {
    snprintf(acStack_50,0x40,"/sys/class/gpio/gpio%d",param_1);
    iVar1 = access(acStack_50,0);
    if (iVar1 == 0) {
      printf("%s:%d","gpio_export",0xb7);
      printf("port %d already exported\n",param_1);
      perror("access error");
      pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
      uVar3 = 0;
    }
    else {
      local_c = open("/sys/class/gpio/export",1);
      if (local_c < 0) {
        printf("%s:%d","gpio_export",0xbf);
        puts("Failed to open export for writing!");
        pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
        uVar3 = 0xfffffffe;
      }
      else {
        local_10 = snprintf(acStack_50,0x40,"%d",param_1);
        sVar2 = write(local_c,acStack_50,local_10);
        if (sVar2 < 0) {
          printf("%s:%d","gpio_export",0xc6);
          printf("Failed to export gpio %d!",param_1);
          close(local_c);
          pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
          uVar3 = 0xfffffffd;
        }
        else {
          printf("%s:%d","gpio_export",0xcb);
          printf("export gpio %d success\n",param_1);
          close(local_c);
          pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
          uVar3 = 0;
        }
      }
    }
  }
  else {
    printf("%s:%d","gpio_export",0xb1);
    puts("failed to api lock");
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

