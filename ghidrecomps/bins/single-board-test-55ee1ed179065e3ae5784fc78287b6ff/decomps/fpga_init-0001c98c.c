
undefined4 fpga_init(void)

{
  undefined4 uVar1;
  
  if (fpga_inited == 0) {
    fpga_fd = open("/dev/axi_fpga_dev",2);
    if (fpga_fd < 0) {
      printf("%s:%d","fpga_init",0x12f);
      printf("/dev/axi_fpga_dev open failed. fd = %d\n",fpga_fd);
      uVar1 = 0xffffffff;
    }
    else {
      axi_fpga_addr = mmap((void *)0x0,0x1200,3,1,fpga_fd,0);
      if (axi_fpga_addr == (void *)0x0) {
        printf("%s:%d","fpga_init",0x136);
        printf("mmap axi_fpga_addr failed. axi_fpga_addr = 0x%x\n",axi_fpga_addr);
        close(fpga_fd);
        uVar1 = 0xfffffffe;
      }
      else {
        printf("%s:%d","fpga_init",0x13a);
        printf("fpga_init success. axi_fpga_addr = 0x%x\n",axi_fpga_addr);
        reset();
        fpga_inited = 1;
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

