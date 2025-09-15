
void set_reset_hashboard(int chainIndex,int resetBit)

{
  uint uVar1;
  int resetBit_local;
  int chainIndex_local;
  char tmp42 [2048];
  char logstr [1024];
  uint resetFlag;
  uint ret;
  
  uVar1 = 1 << (chainIndex & 0xffU);
  if (resetBit < 1) {
    ret = ~uVar1 & axi_fpga_addr[0xd];
  }
  else {
    ret = uVar1 | axi_fpga_addr[0xd];
  }
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"set_reset_hashboard = 0x%08x\n",ret);
    _applog(5,tmp42,false);
  }
  axi_fpga_addr[0xd] = ret;
  return;
}

