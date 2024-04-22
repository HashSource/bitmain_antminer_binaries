
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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
  pthread_create(DAT_00021bc0,(pthread_attr_t *)0x0,show_stats_func_z15_3chips + 1,(void *)0x0);
  init_fpga();
  set_fpga_baud('\x1a');
  check_chain();
  if (gChain == 0xff) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      tmp42[0] = s_____Chain_Check_Fail_0003682c[0];
      tmp42[1] = s_____Chain_Check_Fail_0003682c[1];
      tmp42[2] = s_____Chain_Check_Fail_0003682c[2];
      tmp42[3] = s_____Chain_Check_Fail_0003682c[3];
      tmp42[4] = s_____Chain_Check_Fail_0003682c[4];
      tmp42[5] = s_____Chain_Check_Fail_0003682c[5];
      tmp42[6] = s_____Chain_Check_Fail_0003682c[6];
      tmp42[7] = s_____Chain_Check_Fail_0003682c[7];
      tmp42[8] = s_____Chain_Check_Fail_0003682c[8];
      tmp42[9] = s_____Chain_Check_Fail_0003682c[9];
      tmp42[10] = s_____Chain_Check_Fail_0003682c[10];
      tmp42[11] = s_____Chain_Check_Fail_0003682c[11];
      tmp42[12] = s_____Chain_Check_Fail_0003682c[12];
      tmp42[13] = s_____Chain_Check_Fail_0003682c[13];
      tmp42[14] = s_____Chain_Check_Fail_0003682c[14];
      tmp42[15] = s_____Chain_Check_Fail_0003682c[15];
      tmp42[16] = s_____Chain_Check_Fail_0003682c[16];
      tmp42[17] = s_____Chain_Check_Fail_0003682c[17];
      tmp42[18] = s_____Chain_Check_Fail_0003682c[18];
      tmp42[19] = s_____Chain_Check_Fail_0003682c[19];
      tmp42._20_2_ = (undefined2)ram0x00036840;
      _applog(2,tmp42,false);
    }
    iVar1 = -1;
  }
  else {
    reset_PIC16F1704_pic((uint)gChain,gI2c);
    jump_from_loader_to_app_PIC16F1704((uint)gChain,gI2c);
    pthread_create(DAT_00021bc4,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,chain_info + gChain);
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
      tmp42[0] = s_Test_finished_00036844[0];
      tmp42[1] = s_Test_finished_00036844[1];
      tmp42[2] = s_Test_finished_00036844[2];
      tmp42[3] = s_Test_finished_00036844[3];
      tmp42[4] = s_Test_finished_00036844[4];
      tmp42[5] = s_Test_finished_00036844[5];
      tmp42[6] = s_Test_finished_00036844[6];
      tmp42[7] = s_Test_finished_00036844[7];
      tmp42[8] = s_Test_finished_00036844[8];
      tmp42[9] = s_Test_finished_00036844[9];
      tmp42[10] = s_Test_finished_00036844[10];
      tmp42[11] = s_Test_finished_00036844[11];
      tmp42._12_3_ = (undefined3)ram0x00036850;
      _applog(2,tmp42,false);
    }
    iVar1 = 1;
  }
  return iVar1;
}

