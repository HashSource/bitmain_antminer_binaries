
int bitmain_axi_close(void)

{
  int iVar1;
  
  printf("\n\n--- %s\n","bitmain_axi_close");
  iVar1 = munmap(axi_fpga_addr,0x1200);
  if (iVar1 < 0) {
    puts("munmap failed!");
  }
  iVar1 = munmap(fpga_mem_addr,0x1000000);
  if (iVar1 < 0) {
    puts("munmap failed!");
  }
  close(cgpu._65576_4_);
  iVar1 = fd_fpga_mem;
  close(fd_fpga_mem);
  return iVar1;
}

