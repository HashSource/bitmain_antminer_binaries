
undefined4 singleBoardTest_V9_BM1744_manual(void)

{
  undefined4 uVar1;
  char local_67c [12];
  undefined4 local_670;
  char local_66c [4];
  undefined2 local_668;
  undefined1 auStack_27c [620];
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(local_67c,0x400,"%s[%d]\n","singleBoardTest_V9_BM1744_manual",0x149);
    _applog(2,local_67c,0);
  }
  get_app_config(auStack_27c);
  memset(&sensor_info,0,8);
  memset(nonce_num_each_asic,0,0xc);
  init_fpga();
  set_fpga_baud(0x1a);
  check_chain();
  if (gChain == 0xff) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      builtin_strncpy(local_67c,"--- Chain Ch",0xc);
      local_670._0_1_ = 'e';
      local_670._1_1_ = 'c';
      local_670._2_1_ = 'k';
      local_670._3_1_ = ' ';
      builtin_strncpy(local_66c,"Fail",4);
      local_668 = 10;
      _applog(2,local_67c,0);
    }
    uVar1 = 0xffffffff;
  }
  else {
    reset_PIC16F1704_pic(gChain,gI2c);
    jump_from_loader_to_app_PIC16F1704(gChain,gI2c);
    pthread_create((pthread_t *)(cgpu + 0xc),(pthread_attr_t *)0x0,(__start_routine *)0x2664d,
                   &chain_info + gChain);
    write_axi_fpga(0xd,0xffff);
    usleep(300000);
    enable_PIC16F1704_dc_dc(gChain,gI2c,1);
    usleep(300000);
    write_axi_fpga(0xd,0);
    usleep(300000);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(local_67c,0x400,"%s[%d]\n","singleBoardTest_V9_BM1744_manual",0x167);
      _applog(2,local_67c,0);
    }
    pcba_app_manual_test();
    write_axi_fpga(0xd,0xffff);
    usleep(300000);
    write_axi_fpga(0xd,0);
    usleep(300000);
    enable_PIC16F1704_dc_dc(gChain,gI2c,0);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(cgpu._12_4_);
    pthread_join(cgpu._12_4_,(void **)0x0);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      builtin_strncpy(local_67c,"Test finishe",0xc);
      local_670 = CONCAT13(local_670._3_1_,0xa64);
      _applog(2,local_67c,0);
    }
    uVar1 = 1;
  }
  return uVar1;
}

