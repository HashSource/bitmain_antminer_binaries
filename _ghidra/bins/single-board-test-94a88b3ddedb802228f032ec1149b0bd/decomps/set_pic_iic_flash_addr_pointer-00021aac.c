
void set_pic_iic_flash_addr_pointer(byte param_1,byte param_2,byte param_3)

{
  byte local_1a;
  byte local_19;
  FILE *local_18;
  int local_14;
  
  local_14 = 0;
  do {
    send_pic_command(param_1);
    pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
    write_pic_iic(0,0,0,param_1,1);
    write_pic_iic(0,0,0,param_1,param_2);
    write_pic_iic(0,0,0,param_1,param_3);
    pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
    sleep(1);
    get_pic_iic_flash_addr_pointer(param_1,&local_19,&local_1a);
    if ((param_2 == local_19) && (param_3 == local_1a)) {
      return;
    }
    if (3 < log_level) {
      local_18 = fopen(log_file,"a+");
      if (local_18 != (FILE *)0x0) {
        fprintf(local_18,
                "%s:%d: Error of set PIC FLASH addr: addr_H=%x(%x) addr_L=%x(%x) on Chain[%d]\n",
                "driver-bitmain.c",0x13bc,(uint)param_2,(uint)local_19,(uint)param_3,(uint)local_1a,
                (uint)param_1);
      }
      fclose(local_18);
    }
    reset_iic_pic(param_1);
    sleep(5);
    local_14 = local_14 + 1;
  } while (local_14 < 4);
  if (conf._144_4_ == 0) {
    return;
  }
  sprintf(search_failed_info,"J%d:5",param_1 + 1);
  saveSearchFailedFlagInfo();
  searchStatus = 2;
  do {
    processTEST();
    sleep(1);
  } while( true );
}

