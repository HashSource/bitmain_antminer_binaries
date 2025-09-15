
undefined4 gpio_read(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  ssize_t sVar2;
  undefined4 uVar3;
  char local_50 [68];
  int local_c;
  
  local_50[0] = '\0';
  local_50[1] = '\0';
  local_50[2] = '\0';
  local_50[3] = '\0';
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)api_mutex);
  if (iVar1 == 0) {
    snprintf(local_50 + 4,0x40,"/sys/class/gpio/gpio%d/value",param_1);
    local_c = open(local_50 + 4,0);
    if (local_c < 0) {
      printf("%s:%d","gpio_read",0x136);
      printf("Failed to open gpio %d value for reading!\n",param_1);
      pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
      uVar3 = 0xfffffffe;
    }
    else {
      sVar2 = read(local_c,local_50,4);
      if (sVar2 < 0) {
        printf("%s:%d","gpio_read",0x13c);
        puts("Failed to read value!");
        close(local_c);
        pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
        uVar3 = 0xfffffffd;
      }
      else {
        close(local_c);
        pthread_mutex_unlock((pthread_mutex_t *)api_mutex);
        iVar1 = atoi(local_50);
        *param_2 = (char)iVar1;
        uVar3 = 0;
      }
    }
  }
  else {
    printf("%s:%d","gpio_read",0x12f);
    puts("failed to api lock");
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

