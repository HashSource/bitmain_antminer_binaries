
void set_work_nonce2(uint *value)

{
  uint *value_local;
  char tmp42 [2048];
  uint buf [2];
  
  buf[0] = 0;
  buf[1] = 0;
  axi_fpga_addr[0x42] = *value;
  axi_fpga_addr[0x43] = value[1];
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set WORK_NONCE_2 value[0]: 0x%x, value[1]: 0x%x\n","set_work_nonce2",
             *value,value[1]);
    _applog(7,tmp42,false);
  }
  get_work_nonce2(buf);
  return;
}

