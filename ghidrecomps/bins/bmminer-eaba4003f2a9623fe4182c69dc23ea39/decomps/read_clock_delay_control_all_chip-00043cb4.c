
/* WARNING: Unknown calling convention */

void read_clock_delay_control_all_chip(void)

{
  char tmp42 [2048];
  core_cmd core;
  int asic;
  int i;
  
  core.chain = '\0';
  core.chip_addr = '\0';
  core.mode = '\0';
  core.core_mode = '\x01';
  core.reg_data = 0xff;
  core.core_id = '\0';
  core.cmd_type = '\0';
  core.rw_falg = '\0';
  core.reserved = '\0';
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      for (asic = 0; asic < 0x3c; asic = asic + 1) {
        clear_register_value_buf();
        core.chip_addr = (uchar)((asic & 0xffU) << 1);
        core.chain = (uchar)i;
        set_core_cmd_BM1393(&core);
        check_core_register = 0;
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"--- read chip[%d] clock delay control ---\n",asic);
          _applog(5,tmp42,false);
        }
        check_asic_reg_with_addr_test(0x40,(uchar)((asic & 0xffU) << 1),i,0xd0);
      }
    }
  }
  return;
}

