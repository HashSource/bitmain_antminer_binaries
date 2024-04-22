
void set_reset_allhashboard(int resetBit)

{
  int resetBit_local;
  char tmp42 [2048];
  char logstr [1024];
  uint ret;
  
  if (resetBit < 1) {
    ret = axi_fpga_addr[0xd] & 0xffff0000;
  }
  else {
    ret = ~(~(axi_fpga_addr[0xd] >> 0x10) << 0x10);
  }
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"set_reset_allhashboard = 0x%08x\n",ret);
    _applog(5,tmp42,false);
  }
  axi_fpga_addr[0xd] = ret;
  return;
}

