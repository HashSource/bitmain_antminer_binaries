
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 singleBoardTest_V9_BM1744_manual(void)

{
  undefined4 uVar1;
  undefined4 local_67c;
  undefined4 uStack_678;
  undefined4 uStack_674;
  undefined4 local_670;
  undefined4 local_66c;
  undefined2 local_668;
  undefined auStack_27c [620];
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf((char *)&local_67c,0x400,"%s[%d]\n","singleBoardTest_V9_BM1744_manual",0x159);
    _applog(2,&local_67c,0);
  }
  get_app_config(auStack_27c);
  memset(&sensor_info,0,8);
  memset(nonce_num_each_asic,0,0xc);
  init_fpga();
  set_fpga_baud(0x1a);
  check_chain();
  if (gChain == 0xff) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      local_67c._0_1_ = s_____Chain_Check_Fail_00036614[0];
      local_67c._1_1_ = s_____Chain_Check_Fail_00036614[1];
      local_67c._2_1_ = s_____Chain_Check_Fail_00036614[2];
      local_67c._3_1_ = s_____Chain_Check_Fail_00036614[3];
      uStack_678._0_1_ = s_____Chain_Check_Fail_00036614[4];
      uStack_678._1_1_ = s_____Chain_Check_Fail_00036614[5];
      uStack_678._2_1_ = s_____Chain_Check_Fail_00036614[6];
      uStack_678._3_1_ = s_____Chain_Check_Fail_00036614[7];
      uStack_674._0_1_ = s_____Chain_Check_Fail_00036614[8];
      uStack_674._1_1_ = s_____Chain_Check_Fail_00036614[9];
      uStack_674._2_1_ = s_____Chain_Check_Fail_00036614[10];
      uStack_674._3_1_ = s_____Chain_Check_Fail_00036614[11];
      local_670._0_1_ = s_____Chain_Check_Fail_00036614[12];
      local_670._1_1_ = s_____Chain_Check_Fail_00036614[13];
      local_670._2_1_ = s_____Chain_Check_Fail_00036614[14];
      local_670._3_1_ = s_____Chain_Check_Fail_00036614[15];
      local_66c._0_1_ = s_____Chain_Check_Fail_00036614[16];
      local_66c._1_1_ = s_____Chain_Check_Fail_00036614[17];
      local_66c._2_1_ = s_____Chain_Check_Fail_00036614[18];
      local_66c._3_1_ = s_____Chain_Check_Fail_00036614[19];
      local_668 = (undefined2)ram0x00036628;
      _applog(2,&local_67c,0);
    }
    uVar1 = 0xffffffff;
  }
  else {
    reset_PIC16F1704_pic(gChain,gI2c);
    jump_from_loader_to_app_PIC16F1704(gChain,gI2c);
    pthread_create(DAT_0002b684,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,&chain_info + gChain);
    write_axi_fpga(0xd,0xffff);
    usleep(300000);
    enable_PIC16F1704_dc_dc(gChain,gI2c,1);
    usleep(300000);
    write_axi_fpga(0xd,0);
    usleep(300000);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf((char *)&local_67c,0x400,"%s[%d]\n","singleBoardTest_V9_BM1744_manual",0x177);
      _applog(2,&local_67c,0);
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
      local_67c._0_1_ = s_Test_finished_0003662c[0];
      local_67c._1_1_ = s_Test_finished_0003662c[1];
      local_67c._2_1_ = s_Test_finished_0003662c[2];
      local_67c._3_1_ = s_Test_finished_0003662c[3];
      uStack_678._0_1_ = s_Test_finished_0003662c[4];
      uStack_678._1_1_ = s_Test_finished_0003662c[5];
      uStack_678._2_1_ = s_Test_finished_0003662c[6];
      uStack_678._3_1_ = s_Test_finished_0003662c[7];
      uStack_674._0_1_ = s_Test_finished_0003662c[8];
      uStack_674._1_1_ = s_Test_finished_0003662c[9];
      uStack_674._2_1_ = s_Test_finished_0003662c[10];
      uStack_674._3_1_ = s_Test_finished_0003662c[11];
      _applog(2,&local_67c,0);
    }
    uVar1 = 1;
  }
  return uVar1;
}

