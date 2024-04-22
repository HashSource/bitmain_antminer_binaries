
undefined4 bitmain_axi_close(void)

{
  int iVar1;
  FILE *pFVar2;
  
  iVar1 = munmap(axi_fpga_addr,0x160);
  if ((iVar1 < 0) && (3 < log_level)) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: munmap failed!\n","driver-bitmain.c",0x722);
    }
    fclose(pFVar2);
  }
  iVar1 = munmap(fpga_mem_addr,0x1000000);
  if ((iVar1 < 0) && (3 < log_level)) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: munmap failed!\n","driver-bitmain.c",0x728);
    }
    fclose(pFVar2);
  }
  close(fd);
  close(fd_fpga_mem);
  return 0;
}

