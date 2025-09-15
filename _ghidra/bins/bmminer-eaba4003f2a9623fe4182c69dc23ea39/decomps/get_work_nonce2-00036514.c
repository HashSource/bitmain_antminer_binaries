
int get_work_nonce2(uint *buf)

{
  uint *buf_local;
  char tmp42 [2048];
  int ret;
  
  *buf = axi_fpga_addr[0x42];
  buf[1] = axi_fpga_addr[0x43];
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: WORK_NONCE_2 buf[0]: 0x%x, buf[1]: 0x%x\n","get_work_nonce2",*buf,
             buf[1]);
    _applog(7,tmp42,false);
  }
  return -1;
}

