
uint i2c_write(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 local_1c;
  int *local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  local_1c = param_1;
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  if (iVar1 == 0) {
    local_10 = 0;
    local_18 = (int *)0x0;
    iVar1 = find_c_map(i2c_ctx_map,&local_1c,&local_18);
    if (iVar1 == 1) {
      local_14 = local_18;
      for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
        local_10 = (uint)*(byte *)(param_2 + local_c) |
                   *local_14 << 0x1a | ((uint)local_14[1] >> 4) << 0x14 |
                   ((uint)local_14[1] >> 1 & 7) << 0x10;
        iVar1 = wait4i2c_ready();
        if (iVar1 == 0) {
          free(local_18);
          printf("%s:%d","i2c_write",200);
          puts("iic not ready 4 write");
          pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
          return 0xfffffffe;
        }
        if (platform_is_t9 == 0) {
          fpga_write(v9_fpga_map._44_4_,local_10);
        }
        else {
          fpga_write(DAT_0003557c,local_10);
        }
      }
      free(local_18);
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    }
    else {
      printf("%s:%d","i2c_write",0xd2);
      printf("ctx %d not inited\n",local_1c);
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      param_3 = 0xfffffffe;
    }
  }
  else {
    printf("%s:%d","i2c_write",0xba);
    puts("failed to i2c lock");
    param_3 = 0xffffffff;
  }
  return param_3;
}

