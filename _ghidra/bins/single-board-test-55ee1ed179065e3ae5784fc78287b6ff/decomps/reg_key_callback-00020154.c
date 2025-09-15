
undefined4 reg_key_callback(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
  if (iVar1 == 0) {
    for (local_c = 0; local_c < 5; local_c = local_c + 1) {
      if (*(int *)(ui_callback + local_c * 4) == 0) {
        *(undefined4 *)(ui_callback + local_c * 4) = param_1;
        break;
      }
    }
    if (4 < local_c) {
      local_10 = 0xfffffffe;
      printf("%s:%d","reg_key_callback",0x14b);
      puts("no more listener available");
    }
    pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
  }
  else {
    printf("%s:%d","reg_key_callback",0x140);
    puts("failed to api lock");
    local_10 = 0xffffffff;
  }
  return local_10;
}

