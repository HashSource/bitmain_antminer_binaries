
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

int bm1744_hashboard_init(void)

{
  runtime_base_t *runtime_00;
  int iVar1;
  char tmp42 [1024];
  runtime_base_t *runtime;
  
  runtime_00 = cgpu.runtime;
  fan_control('\x05');
  check_asic_num(runtime_00);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: Check ASIC number: chain %d has %d asic\n","bm1744_hashboard_init",
             runtime_00->chain_id,runtime_00->chain_status[runtime_00->chain_id].real_asic_num);
    _applog(2,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: Expect ASIC number: %d\n","bm1744_hashboard_init",
             runtime_00->chain_status[runtime_00->chain_id].design_asic_num);
    _applog(2,tmp42,false);
  }
  if (runtime_00->chain_status[runtime_00->chain_id].real_asic_num ==
      runtime_00->chain_status[runtime_00->chain_id].design_asic_num) {
    if (app_conf->pcba_only_find_asic == 0) {
      set_asic_address(runtime_00,gChain);
      user_i2c_enable(cgpu.runtime,gChain);
      (*runtime_00->set_core_timeout)(runtime_00->chain_status[gChain].fd,app_conf->core_timeout);
      usleep(10000);
      (*runtime_00->set_ticket_mask)(runtime_00->chain_status[gChain].fd,app_conf->ticket_mask);
      usleep(10000);
      (*runtime_00->set_frequency)(runtime_00->chain_status[gChain].fd,app_conf->pcba_freq);
      usleep(10000);
      (*runtime_00->set_nonce_shift)(runtime_00->chain_status[gChain].fd,0,&runtime_00->nonce_shift)
      ;
      usleep(10000);
      puts("re read asic address:");
      (*runtime_00->read_register)(runtime_00->chain_status[runtime_00->chain_id].fd,1,'\0','\0');
      iVar1 = 0;
    }
    else {
      write_lcd(0,"Find all ASIC!  ",0x10);
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        tmp42[0] = s_Find_all_ASIC_00036704[0];
        tmp42[1] = s_Find_all_ASIC_00036704[1];
        tmp42[2] = s_Find_all_ASIC_00036704[2];
        tmp42[3] = s_Find_all_ASIC_00036704[3];
        tmp42[4] = s_Find_all_ASIC_00036704[4];
        tmp42[5] = s_Find_all_ASIC_00036704[5];
        tmp42[6] = s_Find_all_ASIC_00036704[6];
        tmp42[7] = s_Find_all_ASIC_00036704[7];
        tmp42[8] = s_Find_all_ASIC_00036704[8];
        tmp42[9] = s_Find_all_ASIC_00036704[9];
        tmp42[10] = s_Find_all_ASIC_00036704[10];
        tmp42[11] = s_Find_all_ASIC_00036704[11];
        tmp42._12_3_ = (undefined3)ram0x00036710;
        _applog(2,tmp42,false);
      }
      iVar1 = 1;
    }
  }
  else {
    memset(lcd_output,0x20,0x40);
    write_lcd(0,"Not enough ASIC!",0x10);
    sprintf(DAT_00020efc,"%d ASIC",runtime_00->chain_status[runtime_00->chain_id].real_asic_num);
    write_lcd_no_memset(1,DAT_00020efc,0x10);
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      tmp42[0] = s_Not_enough_ASIC__000366dc[0];
      tmp42[1] = s_Not_enough_ASIC__000366dc[1];
      tmp42[2] = s_Not_enough_ASIC__000366dc[2];
      tmp42[3] = s_Not_enough_ASIC__000366dc[3];
      tmp42[4] = s_Not_enough_ASIC__000366dc[4];
      tmp42[5] = s_Not_enough_ASIC__000366dc[5];
      tmp42[6] = s_Not_enough_ASIC__000366dc[6];
      tmp42[7] = s_Not_enough_ASIC__000366dc[7];
      tmp42[8] = s_Not_enough_ASIC__000366dc[8];
      tmp42[9] = s_Not_enough_ASIC__000366dc[9];
      tmp42[10] = s_Not_enough_ASIC__000366dc[10];
      tmp42[11] = s_Not_enough_ASIC__000366dc[11];
      tmp42[12] = s_Not_enough_ASIC__000366dc[12];
      tmp42[13] = s_Not_enough_ASIC__000366dc[13];
      tmp42[14] = s_Not_enough_ASIC__000366dc[14];
      tmp42[15] = s_Not_enough_ASIC__000366dc[15];
      tmp42._16_2_ = (undefined2)ram0x000366ec;
      _applog(0,tmp42,false);
    }
    iVar1 = -1;
  }
  return iVar1;
}

