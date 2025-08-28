
void bitmain_axi_close(void)

{
  char local_414 [1024];
  int local_14;
  
  local_14 = 0;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(local_414,0x400,"--- %s\n","bitmain_axi_close");
    _applog(2,local_414,0);
  }
  local_14 = munmap(axi_fpga_addr,0x1200);
  if ((local_14 < 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level))))
  {
    builtin_strncpy(local_414,"munmap failed!\n",0x10);
    _applog(2,local_414,0);
  }
  local_14 = munmap(fpga_mem_addr,0x1000000);
  if ((local_14 < 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level))))
  {
    builtin_strncpy(local_414,"munmap failed!\n",0x10);
    _applog(2,local_414,0);
  }
  close(fd_fpga);
  close(fd_fpga_mem);
  return;
}

