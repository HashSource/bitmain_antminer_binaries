
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void fpga_uninit(void)

{
  int iVar1;
  char tmp42 [2048];
  
  if (fpga_inited == 0) {
    return;
  }
  iVar1 = munmap(axi_fpga_addr,0x1200);
  if (iVar1 < 0) {
    builtin_strncpy(tmp42,"munmap failed!\n",0x10);
    _applog(0,tmp42,false);
  }
  iVar1 = munmap(fpga_mem_addr_hal,0x1000000);
  if (iVar1 < 0) {
    builtin_strncpy(tmp42,"munmap fpga_mem_addr_hal failed!",0x20);
    tmp42[0x20] = '\n';
    tmp42[0x21] = '\0';
    _applog(0,tmp42,false);
  }
  fpga_inited = 0;
  close(fpga_fd);
  close(fd_fpga_mem_hal);
  return;
}

