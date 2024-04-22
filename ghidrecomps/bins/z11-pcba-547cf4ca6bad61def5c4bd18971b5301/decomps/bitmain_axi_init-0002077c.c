
undefined4 bitmain_axi_init(void)

{
  char acStack_410 [1024];
  uint local_10;
  undefined4 local_c;
  
  local_c = 0;
  fd_fpga = open("/dev/axi_fpga_dev",2);
  if (fd_fpga < 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_410,0x400,"/dev/axi_fpga_dev open failed. fd = %d\n",fd_fpga);
      _applog(2,acStack_410,0);
    }
    local_c = 0xffffffff;
  }
  else {
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x1200,3,1,fd_fpga,0);
    if (axi_fpga_addr == (uint *)0x0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_410,0x400,"mmap axi_fpga_addr failed. axi_fpga_addr = 0x%p\n",0);
        _applog(2,acStack_410,0);
      }
      local_c = 0xffffffff;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_410,0x400,"mmap axi_fpga_addr = 0x%p\n",axi_fpga_addr);
        _applog(2,acStack_410,0);
      }
      local_10 = *axi_fpga_addr & 0xffff;
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_410,0x400,"axi_fpga_addr data = 0x%x\n",local_10);
        _applog(2,acStack_410,0);
      }
      fd_fpga_mem = open("/dev/fpga_mem",2);
      if (fd_fpga_mem < 0) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(acStack_410,0x400,"/dev/fpga_mem open failed. fd_fpga_mem = %d\n",fd_fpga_mem);
          _applog(2,acStack_410,0);
        }
        local_c = 0xffffffff;
      }
      else {
        fpga_mem_addr = mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem,0);
        if (fpga_mem_addr == (void *)0x0) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
            snprintf(acStack_410,0x400,"mmap fpga_mem_addr failed. fpga_mem_addr = 0x%p\n",0);
            _applog(2,acStack_410,0);
          }
          local_c = 0xffffffff;
        }
        else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(acStack_410,0x400,"mmap fpga_mem_addr = 0x%p\n",fpga_mem_addr);
          _applog(2,acStack_410,0);
        }
      }
    }
  }
  return local_c;
}

