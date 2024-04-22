
/* WARNING: Unknown calling convention */

void scanfreq_read_core_hash_clock_counter(void)

{
  char tmp42 [2048];
  _Bool ready [16];
  core_cmd core;
  _Bool all_ready;
  int asic;
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
  memset(&core,0,0xc);
  core._0_2_ = (ushort)core._0_4_ & 0xff;
  core.mode = '\x01';
  core.core_mode = '\x01';
  core.reg_data = 1;
  core.core_id = '\0';
  core.cmd_type = '\x05';
  core.rw_falg = '\x01';
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      core.chain = (uchar)i;
      set_core_cmd_BM1393(&core);
    }
  }
  sleep(2);
  memset(&core,0,0xc);
  core._0_2_ = (ushort)core._0_4_ & 0xff;
  core.mode = '\0';
  core.core_mode = '\x01';
  core.reg_data = 0;
  core.core_id = '\0';
  core.cmd_type = '\x06';
  core.rw_falg = '\0';
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      for (asic = 0; asic < 0x3c; asic = asic + 1) {
        clear_register_value_buf();
        core.chip_addr = (uchar)((asic & 0xffU) << 1);
        core.chain = (uchar)i;
        set_core_cmd_BM1393(&core);
        check_core_register = 6;
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"--- read chip[%d] hash count ---\n",asic << 1);
          _applog(5,tmp42,false);
        }
        check_asic_reg_with_addr_test(0x40,(uchar)((asic & 0xffU) << 1),i,0xd0);
      }
    }
  }
  return;
}

