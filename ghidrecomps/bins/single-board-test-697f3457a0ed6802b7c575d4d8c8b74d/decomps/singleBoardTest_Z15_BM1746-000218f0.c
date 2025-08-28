
/* WARNING: Unknown calling convention */

int singleBoardTest_Z15_BM1746(void)

{
  int iVar1;
  char tmp42 [1024];
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Start %s[%d]\n","singleBoardTest_Z15_BM1746",0x2a4);
    _applog(2,tmp42,false);
  }
  init_pcba_args();
  pthread_create(&cgpu.show_id,(pthread_attr_t *)0x0,(__start_routine *)0x20a31,(void *)0x0);
  init_fpga();
  set_fpga_baud('\x1a');
  check_chain();
  if (gChain == 0xff) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"--- Chain Check Fail",0x14);
      tmp42[0x14] = '\n';
      tmp42[0x15] = '\0';
      _applog(2,tmp42,false);
    }
    iVar1 = -1;
  }
  else {
    reset_PIC16F1704_pic((uint)gChain,gI2c);
    jump_from_loader_to_app_PIC16F1704((uint)gChain,gI2c);
    pthread_create(&cgpu.pic_heart_beat_id,(pthread_attr_t *)0x0,(__start_routine *)0x1b3e9,
                   chain_info + gChain);
    write_axi_fpga(0xd,0xffff);
    usleep(300000);
    enable_PIC16F1704_dc_dc((uint)gChain,gI2c,'\x01');
    usleep(300000);
    write_axi_fpga(0xd,0);
    vol_init((ushort)app_conf->pcba_voltage);
    usleep(300000);
    start_single_board_test();
    pthread_cancel(cgpu.show_id);
    pthread_join(cgpu.show_id,(void **)0x0);
    V9_print_lcd_type(hardware_exception);
    write_axi_fpga(0xd,0xffff);
    usleep(300000);
    write_axi_fpga(0xd,0);
    usleep(300000);
    enable_PIC16F1704_dc_dc((uint)gChain,gI2c,'\0');
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(cgpu.pic_heart_beat_id);
    pthread_join(cgpu.pic_heart_beat_id,(void **)0x0);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    clear_last_test_results();
    fan_control('\x02');
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"Test finishe",0xc);
      tmp42[0xc] = 'd';
      tmp42[0xd] = '\n';
      tmp42[0xe] = '\0';
      _applog(2,tmp42,false);
    }
    iVar1 = 1;
  }
  return iVar1;
}

