
/* WARNING: Unknown calling convention */

void bitmain_axi_close(void)

{
  int iVar1;
  
  printf("\n\n--- %s\n","bitmain_axi_close");
  iVar1 = munmap(axi_fpga_addr,0x400);
  if (iVar1 < 0) {
    puts("munmap failed!");
  }
  iVar1 = munmap(fpga_mem_addr,0x1000000);
  if (iVar1 < 0) {
    puts("munmap failed!");
  }
  close(*(int *)(DAT_00025d24 + 0x28));
  (*(code *)PTR_close_000301b0)(fd_fpga_mem);
  return;
}

