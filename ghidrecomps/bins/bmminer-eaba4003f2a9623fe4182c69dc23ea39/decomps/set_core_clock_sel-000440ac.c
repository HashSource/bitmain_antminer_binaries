
void set_core_clock_sel(uchar chain,uchar sel_index)

{
  uchar sel_index_local;
  uchar chain_local;
  char tmp42 [2048];
  core_cmd core;
  uchar core_data;
  
  core.chain = '\0';
  core.chip_addr = '\0';
  core.mode = '\x01';
  core.core_mode = '\x01';
  core.reg_data = (uint)(sel_index & 0xf);
  core.core_id = '\0';
  core.cmd_type = '\a';
  core.rw_falg = '\x01';
  core.reserved = '\0';
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"in %s, core_data = 0x%02x","set_core_clock_sel",(uint)(sel_index & 0xf));
    _applog(5,tmp42,false);
  }
  core.chain = chain;
  set_core_cmd_BM1393(&core);
  return;
}

