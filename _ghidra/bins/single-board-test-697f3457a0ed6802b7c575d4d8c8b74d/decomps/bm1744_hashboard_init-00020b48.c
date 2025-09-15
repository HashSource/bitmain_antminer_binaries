
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
        builtin_strncpy(tmp42,"Find all ASI",0xc);
        tmp42[0xc] = 'C';
        tmp42[0xd] = '\n';
        tmp42[0xe] = '\0';
        _applog(2,tmp42,false);
      }
      iVar1 = 1;
    }
  }
  else {
    memset(lcd_output,0x20,0x40);
    write_lcd(0,"Not enough ASIC!",0x10);
    sprintf(lcd_output[1],"%d ASIC",runtime_00->chain_status[runtime_00->chain_id].real_asic_num);
    write_lcd_no_memset(1,lcd_output[1],0x10);
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      builtin_strncpy(tmp42,"Not enough ASIC!",0x10);
      tmp42[0x10] = '\n';
      tmp42[0x11] = '\0';
      _applog(0,tmp42,false);
    }
    iVar1 = -1;
  }
  return iVar1;
}

