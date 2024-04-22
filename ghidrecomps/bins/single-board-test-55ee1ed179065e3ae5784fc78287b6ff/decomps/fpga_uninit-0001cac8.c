
void fpga_uninit(void)

{
  int iVar1;
  
  if (fpga_inited != 0) {
    iVar1 = munmap(axi_fpga_addr,0x1200);
    if (iVar1 < 0) {
      printf("%s:%d","fpga_uninit",0x14a);
      puts("munmap failed!");
    }
    fpga_inited = 0;
    close(fpga_fd);
  }
  return;
}

