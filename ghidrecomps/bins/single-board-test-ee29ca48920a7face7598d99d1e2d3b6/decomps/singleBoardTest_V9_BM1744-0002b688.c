
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 singleBoardTest_V9_BM1744(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined2 local_400;
  undefined4 local_14;
  
  local_14 = 0;
  memset(&sensor_info,0,8);
  memset(one_work_nonce_each_asic,0,0xc);
  memset(one_work_invalid_nonce_each_asic_2,0,0x18);
  show_id_alive = 1;
  pthread_create(DAT_0002b97c,(pthread_attr_t *)0x0,show_stats_func_z11_3chips + 1,(void *)0x0);
  init_fpga();
  set_fpga_baud(0x1a);
  check_chain();
  if (gChain == 0xff) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      local_414._0_1_ = s_____Chain_Check_Fail_00036614[0];
      local_414._1_1_ = s_____Chain_Check_Fail_00036614[1];
      local_414._2_1_ = s_____Chain_Check_Fail_00036614[2];
      local_414._3_1_ = s_____Chain_Check_Fail_00036614[3];
      uStack_410._0_1_ = s_____Chain_Check_Fail_00036614[4];
      uStack_410._1_1_ = s_____Chain_Check_Fail_00036614[5];
      uStack_410._2_1_ = s_____Chain_Check_Fail_00036614[6];
      uStack_410._3_1_ = s_____Chain_Check_Fail_00036614[7];
      uStack_40c._0_1_ = s_____Chain_Check_Fail_00036614[8];
      uStack_40c._1_1_ = s_____Chain_Check_Fail_00036614[9];
      uStack_40c._2_1_ = s_____Chain_Check_Fail_00036614[10];
      uStack_40c._3_1_ = s_____Chain_Check_Fail_00036614[11];
      local_408._0_1_ = s_____Chain_Check_Fail_00036614[12];
      local_408._1_1_ = s_____Chain_Check_Fail_00036614[13];
      local_408._2_1_ = s_____Chain_Check_Fail_00036614[14];
      local_408._3_1_ = s_____Chain_Check_Fail_00036614[15];
      local_404._0_1_ = s_____Chain_Check_Fail_00036614[16];
      local_404._1_1_ = s_____Chain_Check_Fail_00036614[17];
      local_404._2_1_ = s_____Chain_Check_Fail_00036614[18];
      local_404._3_1_ = s_____Chain_Check_Fail_00036614[19];
      local_400 = (undefined2)ram0x00036628;
      _applog(2,&local_414,0);
    }
    uVar2 = 0xffffffff;
  }
  else {
    reset_PIC16F1704_pic(gChain,gI2c);
    jump_from_loader_to_app_PIC16F1704(gChain,gI2c);
    pthread_create(DAT_0002b980,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,&chain_info + gChain);
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
    sleep(1);
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
    clear_last_test_results();
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      local_414._0_1_ = s_Test_finished_0003662c[0];
      local_414._1_1_ = s_Test_finished_0003662c[1];
      local_414._2_1_ = s_Test_finished_0003662c[2];
      local_414._3_1_ = s_Test_finished_0003662c[3];
      uStack_410._0_1_ = s_Test_finished_0003662c[4];
      uStack_410._1_1_ = s_Test_finished_0003662c[5];
      uStack_410._2_1_ = s_Test_finished_0003662c[6];
      uStack_410._3_1_ = s_Test_finished_0003662c[7];
      uStack_40c._0_1_ = s_Test_finished_0003662c[8];
      uStack_40c._1_1_ = s_Test_finished_0003662c[9];
      uStack_40c._2_1_ = s_Test_finished_0003662c[10];
      uStack_40c._3_1_ = s_Test_finished_0003662c[11];
      _applog(2,&local_414,0);
    }
    uVar2 = 1;
  }
  return uVar2;
}

