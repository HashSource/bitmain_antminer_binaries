
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_nonce2_jobid_phy_addr(void)

{
  char tmp42 [2048];
  sysinfo si;
  
  sysinfo((sysinfo *)&si);
  if (si.totalram < 0x3b9aca01) {
    if (si.totalram < 0x1dcd6501) {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        builtin_strncpy(tmp42,"Detect 256MB control board of XILINX",0x24);
        tmp42[0x24] = '\n';
        tmp42[0x25] = '\0';
        _applog(5,tmp42,false);
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        builtin_strncpy(tmp42,"Detect 512MB control board of XILINX",0x24);
        tmp42[0x24] = '\n';
        tmp42[0x25] = '\0';
        _applog(5,tmp42,false);
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      builtin_strncpy(tmp42,"Detect 1GB control board of XILINX\n",0x24);
      _applog(5,tmp42,false);
    }
  }
  return;
}

