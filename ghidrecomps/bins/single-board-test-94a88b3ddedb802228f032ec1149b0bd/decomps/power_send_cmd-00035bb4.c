
bool power_send_cmd(int param_1,byte param_2,int param_3,byte param_4)

{
  undefined uVar1;
  int iVar2;
  FILE *__stream;
  byte local_12;
  byte local_11;
  
  local_12 = 0;
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  while (local_12 < 3) {
    for (local_11 = 0; local_11 < param_2; local_11 = local_11 + 1) {
      znyq_set_iic(0x10,1,0,1,0x11,*(undefined *)((uint)local_11 + param_1));
    }
    usleep(500000);
    for (local_11 = 0; local_11 < param_4; local_11 = local_11 + 1) {
      uVar1 = znyq_set_iic(0x10,1,1,0,0x11,0);
      *(undefined *)(param_3 + (uint)local_11) = uVar1;
    }
    iVar2 = power_check_reply(param_1,param_3,param_4);
    if (iVar2 != 0) break;
    local_12 = local_12 + 1;
    if (3 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: power send cmd 0x%02x failed, retry for %d times\n","power.c",0x38b
                ,(uint)*(byte *)(param_1 + 2),(uint)local_12);
      }
      fclose(__stream);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return local_12 < 3;
}

