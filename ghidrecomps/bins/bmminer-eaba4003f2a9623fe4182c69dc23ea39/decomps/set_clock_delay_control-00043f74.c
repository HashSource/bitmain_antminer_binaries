
/* WARNING: Unknown calling convention */

void set_clock_delay_control(void)

{
  char tmp42 [2048];
  core_cmd core;
  uchar core_data;
  uchar i;
  
  g_Clock_delay_control = g_Clock_delay_control | 2;
  core.chain = '\0';
  core.chip_addr = '\0';
  core.mode = '\x01';
  core.core_mode = '\x01';
  core.reg_data = (uint)g_Clock_delay_control;
  core.core_id = '\0';
  core.cmd_type = '\0';
  core.rw_falg = '\x01';
  core.reserved = '\0';
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"in %s, core_data = 0x%02x","set_clock_delay_control",
             (uint)g_Clock_delay_control);
    _applog(5,tmp42,false);
  }
  for (i = '\0'; i < 0x10; i = i + '\x01') {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      core.chain = i;
      set_core_cmd_BM1393(&core);
    }
  }
  return;
}

