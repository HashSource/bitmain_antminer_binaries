
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bitmain_axi_close(void)

{
  int iVar1;
  char tmp42 [1024];
  int ret;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","bitmain_axi_close");
    _applog(2,tmp42,false);
  }
  iVar1 = munmap(axi_fpga_addr,0x1200);
  if ((iVar1 < 0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level))))
  {
    builtin_strncpy(tmp42,"munmap failed!\n",0x10);
    _applog(2,tmp42,false);
  }
  iVar1 = munmap(fpga_mem_addr,0x1000000);
  if ((iVar1 < 0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level))))
  {
    builtin_strncpy(tmp42,"munmap failed!\n",0x10);
    _applog(2,tmp42,false);
  }
  close(fd_fpga);
  close(fd_fpga_mem);
  return;
}

