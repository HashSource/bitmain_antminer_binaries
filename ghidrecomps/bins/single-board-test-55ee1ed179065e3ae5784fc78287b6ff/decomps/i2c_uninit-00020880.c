
void i2c_uninit(undefined4 param_1)

{
  int iVar1;
  undefined4 local_1c [2];
  code **local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_1c[0] = param_1;
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  if (iVar1 == 0) {
    iVar1 = exists_c_map(i2c_ctx_map,local_1c);
    if (iVar1 == 1) {
      printf("%s:%d","i2c_uninit",0x42);
      printf("remove %d from callback list\n",local_1c[0]);
      remove_c_map(i2c_ctx_map,local_1c);
    }
    else {
      printf("%s:%d","i2c_uninit",0x45);
      printf("ctx(%d) is not inited\n",local_1c[0]);
    }
    local_14 = (code **)new_iterator_c_map(i2c_ctx_map);
    local_10 = (**local_14)(local_14);
    while (local_10 != 0) {
      local_c = local_c + 1;
      local_10 = (**local_14)(local_14);
    }
    delete_iterator_c_map(local_14);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    if (local_c == 0) {
      printf("%s:%d","i2c_uninit",0x50);
      puts("all i2c uninited");
      i2c_index = 0;
      delete_c_map(i2c_ctx_map);
      i2c_ctx_map = 0;
    }
    else {
      printf("%s:%d","i2c_uninit",0x55);
      printf("still have %d nodes\n",local_c);
    }
  }
  else {
    printf("%s:%d","i2c_uninit",0x3e);
    puts("failed to i2c lock");
  }
  return;
}

