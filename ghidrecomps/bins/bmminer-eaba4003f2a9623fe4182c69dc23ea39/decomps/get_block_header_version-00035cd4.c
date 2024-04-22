
/* WARNING: Unknown calling convention */

int get_block_header_version(void)

{
  uint uVar1;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[0x4c];
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: BLOCK_HEADER_VERSION is 0x%x\n","get_block_header_version",uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

