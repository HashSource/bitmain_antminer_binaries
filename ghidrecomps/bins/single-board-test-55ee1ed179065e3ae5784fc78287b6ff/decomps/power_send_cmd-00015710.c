
bool power_send_cmd(int param_1,byte param_2,int param_3,byte param_4)

{
  undefined uVar1;
  int iVar2;
  byte local_12;
  byte local_11;
  
  local_12 = 0;
  pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
  while (local_12 < 3) {
    for (local_11 = 0; local_11 < param_2; local_11 = local_11 + 1) {
      znyq_set_iic(0x10,1,0,1,0x11,*(undefined *)(param_1 + (uint)local_11));
    }
    usleep(500000);
    for (local_11 = 0; local_11 < param_4; local_11 = local_11 + 1) {
      uVar1 = znyq_set_iic(0x10,1,1,0,0x11,0);
      *(undefined *)(param_3 + (uint)local_11) = uVar1;
      printf("%s, reply_buf[%d]=%02x\n","power_send_cmd",(uint)local_11,
             (uint)*(byte *)(param_3 + (uint)local_11));
    }
    iVar2 = power_check_reply(param_1,param_3,param_4);
    if (iVar2 != 0) break;
    local_12 = local_12 + 1;
    printf("power send cmd 0x%02x failed, retry for %d times\n",(uint)*(byte *)(param_1 + 3),
           (uint)local_12);
  }
  pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
  return local_12 < 3;
}

