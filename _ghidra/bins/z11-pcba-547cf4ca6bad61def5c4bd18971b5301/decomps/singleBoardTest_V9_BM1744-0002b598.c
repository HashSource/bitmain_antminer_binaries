
undefined4 singleBoardTest_V9_BM1744(void)

{
  int iVar1;
  undefined4 uVar2;
  char local_414 [12];
  undefined4 local_408;
  char local_404 [4];
  undefined2 local_400;
  undefined4 local_14;
  
  local_14 = 0;
  memset(&sensor_info,0,8);
  memset(one_work_nonce_each_asic,0,0xc);
  memset(one_work_invalid_nonce_each_asic_2,0,0x18);
  show_id_alive = 1;
  pthread_create((pthread_t *)(cgpu + 8),(pthread_attr_t *)0x0,(__start_routine *)0x2b1b9,
                 (void *)0x0);
  init_fpga();
  set_fpga_baud(0x1a);
  check_chain();
  if (gChain == 0xff) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      builtin_strncpy(local_414,"--- Chain Ch",0xc);
      local_408._0_1_ = 'e';
      local_408._1_1_ = 'c';
      local_408._2_1_ = 'k';
      local_408._3_1_ = ' ';
      builtin_strncpy(local_404,"Fail",4);
      local_400 = 10;
      _applog(2,local_414,0);
    }
    uVar2 = 0xffffffff;
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
    iVar1 = isl_communication_check(app_conf._416_4_ & 0xffff);
    if (iVar1 < 1) {
      local_14 = 1;
    }
    else {
      if (app_conf._420_4_ == 1) {
        vol_init(app_conf._416_4_ & 0xffff);
      }
      usleep(300000);
      start_single_board_test();
      local_14 = 0;
    }
    show_id_alive = 0;
    pthread_cancel(cgpu._8_4_);
    pthread_join(cgpu._8_4_,(void **)0x0);
    V9_print_lcd_type(local_14);
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
      builtin_strncpy(local_414,"Test finishe",0xc);
      local_408 = CONCAT13(local_408._3_1_,0xa64);
      _applog(2,local_414,0);
    }
    uVar2 = 1;
  }
  return uVar2;
}

