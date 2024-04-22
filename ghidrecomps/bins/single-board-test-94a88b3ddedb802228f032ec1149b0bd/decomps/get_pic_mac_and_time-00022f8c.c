
void get_pic_mac_and_time(undefined param_1,byte param_2,undefined *param_3,undefined *param_4)

{
  undefined uVar1;
  undefined *puVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  puts("get_pic_mac_and_time");
  if (param_2 < 2) {
    send_pic_command(param_1);
    pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
    write_pic_iic(0,0,0,param_1,0x20);
    write_pic_iic(0,0,0,param_1,param_2);
    usleep(100000);
    pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
    send_pic_command(param_1);
    pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
    write_pic_iic(0,0,0,param_1,0x21);
    for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
      puVar2 = (undefined *)((int)&local_24 + local_14);
      uVar1 = write_pic_iic(1,0,0,param_1,0);
      *puVar2 = uVar1;
    }
    pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
    *param_3 = (undefined)local_24;
    param_3[1] = local_24._2_1_;
    param_3[2] = (undefined)local_20;
    param_3[3] = local_20._2_1_;
    param_3[4] = (undefined)local_1c;
    param_3[5] = local_1c._2_1_;
    for (local_14 = 0; local_14 < 6; local_14 = local_14 + 1) {
      printf("%s: mac[%d] = 0x%02x\n","get_pic_mac_and_time",local_14,(uint)(byte)param_3[local_14])
      ;
    }
    *param_4 = local_24._1_1_;
    param_4[1] = local_24._3_1_;
    param_4[2] = local_20._1_1_;
    param_4[3] = local_20._3_1_;
    param_4[4] = (undefined)local_18;
    param_4[5] = local_18._2_1_;
    for (local_14 = 0; local_14 < 6; local_14 = local_14 + 1) {
      printf("%s: date[%d] = 0x%02x\n","get_pic_mac_and_time",local_14,(uint)(byte)param_4[local_14]
            );
    }
  }
  else {
    printf("%s: There are only 2 mac address, they are MAC0 to MAC1\n","get_pic_mac_and_time");
  }
  return;
}

