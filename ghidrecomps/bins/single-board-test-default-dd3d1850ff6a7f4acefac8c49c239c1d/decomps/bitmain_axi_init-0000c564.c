
undefined4 bitmain_axi_init(void)

{
  undefined4 uVar1;
  
  cgpu._65576_4_ = open("/dev/axi_fpga_dev",2);
  if ((int)cgpu._65576_4_ < 0) {
    printf("/dev/axi_fpga_dev open failed. fd = %d\n",cgpu._65576_4_);
    uVar1 = 0xffffffff;
  }
  else {
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x1200,3,1,cgpu._65576_4_,0);
    if (axi_fpga_addr == (uint *)0x0) {
      printf("mmap axi_fpga_addr failed. axi_fpga_addr = 0x%x\n",0);
      uVar1 = 0xffffffff;
    }
    else {
      printf("mmap axi_fpga_addr = 0x%x\n",axi_fpga_addr);
      printf("axi_fpga_addr data = 0x%x\n",*axi_fpga_addr & 0xffff);
      fd_fpga_mem = open("/dev/fpga_mem",2);
      if (fd_fpga_mem < 0) {
        printf("/dev/fpga_mem open failed. fd_fpga_mem = %d\n",fd_fpga_mem);
        uVar1 = 0xffffffff;
      }
      else {
        fpga_mem_addr = mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem,0);
        if (fpga_mem_addr == (void *)0x0) {
          printf("mmap fpga_mem_addr failed. fpga_mem_addr = 0x%x\n",0);
          uVar1 = 0xffffffff;
        }
        else {
          printf("mmap fpga_mem_addr = 0x%x\n",fpga_mem_addr);
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}

