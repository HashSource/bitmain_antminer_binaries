
/* WARNING: Unknown calling convention */

void read_clock_delay_control_all_chip_one_core(void)

{
  char tmp42 [2048];
  core_cmd core;
  int m;
  int i;
  
  core.chain = '\0';
  core.chip_addr = '\0';
  core.mode = '\0';
  core.core_mode = '\0';
  core.core_id = '\0';
  core.cmd_type = '\0';
  core.rw_falg = '\0';
  core.reserved = '\0';
  core.reg_data = 0;
  memset(core_hash_clock_delay_control,0xff,0x100000);
  core._0_2_ = (ushort)core._0_4_ & 0xff;
  core.mode = '\x01';
  core.core_mode = '\0';
  core.reg_data = 0xff;
  core._4_3_ = CONCAT21(0,core.core_id);
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      for (m = 0; m < 0xd0; m = m + 1) {
        clear_register_value_buf();
        core.core_id = (uchar)m;
        core.chain = (uchar)i;
        set_core_cmd_BM1393(&core);
        check_core_register = 0;
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"--- read all chip core[%d] clock delay control ---\n",m);
          _applog(5,tmp42,false);
        }
        check_asic_reg_with_addr_test(0x40,'\0',i,0x6c);
      }
    }
  }
  return;
}

