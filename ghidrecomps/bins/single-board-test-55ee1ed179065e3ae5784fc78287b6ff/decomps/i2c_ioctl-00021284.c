
undefined4 i2c_ioctl(int param_1,short param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  code *local_14;
  code **local_10;
  int local_c;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  if (iVar1 == 0) {
    local_10 = (code **)new_iterator_c_map(i2c_ctx_map);
    local_c = (**local_10)(local_10);
    while (local_c != 0) {
      local_14 = local_10[5];
      if (param_1 == ***(int ***)(local_14 + 0x10)) {
        local_18 = (undefined4 *)(*local_10[2])(local_c);
        if (param_2 == 0x703) {
          local_20 = *local_18;
          local_1c = param_3;
          (*local_10[1])(local_10,&local_20,8);
          printf("%s:%d",__FUNCTION___6884,0x168);
          printf("update the slave address to %d\n",param_3);
          free(local_18);
        }
        break;
      }
      local_c = (**local_10)(local_10);
    }
    delete_iterator_c_map(local_10);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    uVar2 = 0;
  }
  else {
    printf("%s:%d",__FUNCTION___6884,0x15a);
    puts("failed to i2c lock");
    uVar2 = 0xfffffffc;
  }
  return uVar2;
}

