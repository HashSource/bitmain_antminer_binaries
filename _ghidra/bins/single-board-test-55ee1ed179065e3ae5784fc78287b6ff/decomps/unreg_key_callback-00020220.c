
undefined4 unreg_key_callback(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
  if (iVar1 == 0) {
    for (local_c = 0; local_c < 5; local_c = local_c + 1) {
      if (*(int *)(ui_callback + local_c * 4) == param_1) {
        *(undefined4 *)(ui_callback + local_c * 4) = 0;
        break;
      }
    }
    if (4 < local_c) {
      printf("%s:%d","unreg_key_callback",0x165);
      puts("listener not registered before");
    }
    pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
    uVar2 = 0;
  }
  else {
    printf("%s:%d","unreg_key_callback",0x15b);
    puts("failed to api lock");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

