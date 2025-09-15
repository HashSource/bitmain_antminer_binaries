
int get_pre_header_hash(uint *buf)

{
  uint *buf_local;
  char tmp42 [2048];
  int ret;
  
  *buf = axi_fpga_addr[0x50];
  buf[1] = axi_fpga_addr[0x51];
  buf[2] = axi_fpga_addr[0x52];
  buf[3] = axi_fpga_addr[0x53];
  buf[4] = axi_fpga_addr[0x54];
  buf[5] = axi_fpga_addr[0x55];
  buf[6] = axi_fpga_addr[0x56];
  buf[7] = axi_fpga_addr[0x57];
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,
             "%s: PRE_HEADER_HASH buf[0]: 0x%x, buf[1]: 0x%x, buf[2]: 0x%x, buf[3]: 0x%x, buf[4]: 0x%x, buf[5]: 0x%x, buf[6]: 0x%x, buf[7]: 0x%x\n"
             ,"get_pre_header_hash",*buf,buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7]);
    _applog(7,tmp42,false);
  }
  return buf[7];
}

