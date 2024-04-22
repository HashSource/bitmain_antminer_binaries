
void rewrite_clock_delay_control(uchar chain,uchar chip_addr,uchar core_id,uchar core_data)

{
  undefined4 uVar1;
  uchar core_data_local;
  uchar core_id_local;
  uchar chip_addr_local;
  uchar chain_local;
  char tmp42 [2048];
  core_cmd core;
  
  core.chain = '\0';
  core.chip_addr = '\0';
  core.mode = '\0';
  core.core_mode = '\0';
  core.core_id = '\0';
  core.cmd_type = '\0';
  core.rw_falg = '\0';
  core.reserved = '\0';
  core.reg_data = 0;
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"rewirte chain %d chip %d core %d clock delay, data=%d",(uint)chain,
             (uint)chip_addr,(uint)core_id,(uint)core_data);
    _applog(5,tmp42,false);
  }
  uVar1 = core._4_4_;
  core._4_2_ = CONCAT11('\0',core_id);
  core.reg_data = (uint)core_data;
  core.reserved = SUB41(uVar1,3);
  core._4_3_ = CONCAT12('\x01',core._4_2_);
  core.chip_addr = chip_addr;
  core.chain = chain;
  core.mode = '\0';
  core.core_mode = '\0';
  set_core_cmd_BM1393(&core);
  return;
}

