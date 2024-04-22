
/* WARNING: Unknown calling convention */

int check_chain(void)

{
  uint uVar1;
  int iVar2;
  char tmp42 [1024];
  int ret;
  uchar which_chain;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","check_chain");
    _applog(2,tmp42,false);
  }
  cgpu.chain_num = 0;
  uVar1 = read_axi_fpga(2);
  if (((uVar1 == 1) || (uVar1 == 2)) || ((uVar1 == 4 || (uVar1 == 8)))) {
    which_chain = '\0';
    while (which_chain == '\0') {
      chain_info[0].which_chain = '\0';
      chain_info[0].which_i2c = '\0';
      if ((uVar1 & 1) == 0) {
        cgpu.chain_exist[0] = 0;
      }
      else {
        cgpu.chain_exist[0] = 1;
        cgpu.chain_num = cgpu.chain_num + 1;
        gChain = which_chain;
        (cgpu.runtime)->chain_id = 0;
        gI2c = '\0';
        chain_info[0].which_chain = '\0';
        chain_info[0].which_i2c = '\0';
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"%s: gChain = %d, gI2c = %d\n","check_chain",(uint)gChain,0);
          _applog(2,tmp42,false);
        }
      }
      which_chain = '\x01';
    }
    iVar2 = 0;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: Test zhiju only support 1 plug, but now is 0x%08x\n","check_chain",
               uVar1);
      _applog(2,tmp42,false);
    }
    iVar2 = -1;
  }
  return iVar2;
}

