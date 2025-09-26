
/* WARNING: Unknown calling convention */

int32_t fpga_init(void)

{
  int32_t iVar1;
  char tmp42 [2048];
  
  fpga_fd = open("/dev/axi_fpga_dev",2);
  if (fpga_fd < 0) {
    snprintf(tmp42,0x800,"/dev/axi_fpga_dev open failed. fd = %d\n",fpga_fd);
    _applog(0,tmp42,false);
    iVar1 = -1;
  }
  else {
    axi_fpga_addr = (uint32_t *)mmap((void *)0x0,0x1200,3,1,fpga_fd,0);
    if (axi_fpga_addr == (uint32_t *)0x0) {
      snprintf(tmp42,0x800,"mmap axi_fpga_addr failed. axi_fpga_addr = %p\n",0);
      _applog(0,tmp42,false);
      close(fpga_fd);
      iVar1 = -2;
    }
    else {
      fd_fpga_mem_hal = open("/dev/fpga_mem",2);
      if (fd_fpga_mem_hal < 0) {
        snprintf(tmp42,0x800,"/dev/fpga_mem open failed. fd_fpga_mem_hal = %d\n",fd_fpga_mem_hal);
        _applog(0,tmp42,false);
        perror("open");
        munmap(axi_fpga_addr,0x1200);
        close(fpga_fd);
        iVar1 = -1;
      }
      else {
        fpga_mem_addr_hal = (uint32_t *)mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem_hal,0);
        if (fpga_mem_addr_hal == (uint32_t *)0x0) {
          snprintf(tmp42,0x800,"mmap fpga_mem_addr_hal failed. fpga_mem_addr_hal = 0x%x\n",0);
          _applog(0,tmp42,false);
          munmap(axi_fpga_addr,0x1200);
          close(fpga_fd);
          close(fd_fpga_mem_hal);
          iVar1 = -1;
        }
        else {
          snprintf(tmp42,0x800,"mmap fpga_mem_addr_hal = 0x%x\n",fpga_mem_addr_hal);
          _applog(3,tmp42,false);
          iVar1 = 0;
          fpga_inited = 1;
        }
      }
    }
  }
  return iVar1;
}

