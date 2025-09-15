
/* WARNING: Unknown calling convention */

void * read_all_sensor(void)

{
  runtime_base_t *runtime_00;
  int iVar1;
  int chip_addr_00;
  char tmp42 [1024];
  int chip_addr;
  runtime_base_t *runtime;
  int high_temp_alarm_counter;
  int pcb_high_temp;
  int chip_high_temp;
  int which_asic;
  int i;
  
  runtime_00 = cgpu.runtime;
  high_temp_alarm_counter = 0;
  while (runtime_00->start_recv != 0) {
    for (i = 0; i < runtime_00->sensor_num; i = i + 1) {
      iVar1 = runtime_00->sensor_pos[i];
      chip_addr_00 = iVar1 * runtime_00->addr_interval;
      user_read_iic(runtime_00,chip_addr_00,'L','\x01',chip_temp + iVar1,1);
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"ASIC %d chip temp %d\n",iVar1,(uint)chip_temp[iVar1]);
        _applog(2,tmp42,false);
      }
      user_read_iic(runtime_00,chip_addr_00,'L','\0',pcb_temp + iVar1,1);
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"ASIC %d pcb temp %d\n",iVar1,(uint)pcb_temp[iVar1]);
        _applog(2,tmp42,false);
      }
    }
    pcb_high_temp = 0;
    chip_high_temp = 0;
    for (which_asic = 0; which_asic < 3; which_asic = which_asic + 1) {
      if ((uint)chip_high_temp < (uint)chip_temp[which_asic]) {
        chip_high_temp = (int)chip_temp[which_asic];
      }
      if ((uint)pcb_high_temp < (uint)pcb_temp[which_asic]) {
        pcb_high_temp = (int)pcb_temp[which_asic];
      }
    }
    chip_high = (uint8_t)chip_high_temp;
    pcb_high = (uint8_t)pcb_high_temp;
    if (app_conf->pcba_tempture_high < chip_high_temp) {
      high_temp_alarm_counter = high_temp_alarm_counter + 1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"temperature alarm counter %d\n",high_temp_alarm_counter);
        _applog(2,tmp42,false);
      }
      if (1 < high_temp_alarm_counter) {
        hardware_exception = 1;
      }
    }
    else {
      high_temp_alarm_counter = 0;
    }
    sleep(2);
  }
  return (void *)0x0;
}

