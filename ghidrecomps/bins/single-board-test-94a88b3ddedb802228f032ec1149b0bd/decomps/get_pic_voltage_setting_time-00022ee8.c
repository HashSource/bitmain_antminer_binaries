
void get_pic_voltage_setting_time(undefined param_1,int param_2)

{
  undefined uVar1;
  int local_14;
  
  puts("get_pic_voltage_setting_time");
  send_pic_command(param_1);
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  write_pic_iic(0,0,0,param_1,0x19);
  for (local_14 = 0; local_14 < 6; local_14 = local_14 + 1) {
    uVar1 = write_pic_iic(1,0,0,param_1,0);
    *(undefined *)(param_2 + local_14) = uVar1;
    printf("%s: time[%d] = 0x%02x\n","get_pic_voltage_setting_time",local_14,
           (uint)*(byte *)(local_14 + param_2));
  }
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return;
}

