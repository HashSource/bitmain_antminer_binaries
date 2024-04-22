
/* WARNING: Unknown calling convention */

int bitmain_axi_init(void)

{
  int iVar1;
  
  iVar1 = open("/dev/axi_fpga_dev",2);
  *(int *)(DAT_00025cb0 + 0x28) = iVar1;
  if (iVar1 < 0) {
    printf("/dev/axi_fpga_dev open failed. fd = %d\n");
    iVar1 = -1;
  }
  else {
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x400,3,1,iVar1,0);
    if (axi_fpga_addr == (uint *)0x0) {
      printf("mmap axi_fpga_addr failed. axi_fpga_addr = %p\n",0);
      iVar1 = -1;
    }
    else {
      printf("mmap axi_fpga_addr = %p\n",axi_fpga_addr);
      printf("axi_fpga_addr data = 0x%x\n",(uint)*(ushort *)axi_fpga_addr);
      fd_fpga_mem = open("/dev/fpga_mem",2);
      if (fd_fpga_mem < 0) {
        printf("/dev/fpga_mem open failed. fd_fpga_mem = %d\n",fd_fpga_mem);
        iVar1 = -1;
      }
      else {
        fpga_mem_addr = (uint *)mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem,0);
        if (fpga_mem_addr == (uint *)0x0) {
          printf("mmap fpga_mem_addr failed. fpga_mem_addr = %p\n",0);
          iVar1 = -1;
        }
        else {
          printf("mmap fpga_mem_addr = %p\n",fpga_mem_addr);
          iVar1 = 0;
        }
      }
    }
  }
  return iVar1;
}

