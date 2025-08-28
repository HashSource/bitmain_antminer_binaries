
/* WARNING: Unknown calling convention */

int bitmain_axi_close(void)

{
  int iVar1;
  int extraout_r3;
  char tmp42 [2048];
  int ret;
  
  iVar1 = munmap(axi_fpga_addr,0x160);
  if (((iVar1 < 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    builtin_strncpy(tmp42,"munmap failed!\n",0x10);
    _applog(7,tmp42,false);
  }
  iVar1 = munmap(fpga_mem_addr,0x1000000);
  if (((iVar1 < 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    builtin_strncpy(tmp42,"munmap failed!\n",0x10);
    _applog(7,tmp42,false);
  }
  close(fd);
  close(fd_fpga_mem);
  return extraout_r3;
}

