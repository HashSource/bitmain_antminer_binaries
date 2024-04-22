
undefined4 main(void)

{
  int __fd;
  undefined4 uVar1;
  byte local_9;
  
  __fd = open("/dev/axi_fpga_dev",2);
  if (__fd < 0) {
    printf("/dev/axi_fpga_dev open failed. fd = %d\n",__fd);
    perror("open");
    uVar1 = 0xffffffff;
  }
  else {
    axi_fpga_addr = mmap((void *)0x0,0x160,3,1,__fd,0);
    if (axi_fpga_addr == (void *)0x0) {
      printf("mmap axi_fpga_addr failed. axi_fpga_addr = 0x%lsx\n",0);
      uVar1 = 0xffffffff;
    }
    else {
      system("killall cgminer");
      chain_num = check_chain_num();
      local_9 = 0;
      while( true ) {
        if (chain_num <= (int)(uint)local_9) break;
        if (*(int *)(chain_list + (uint)local_9 * 4) != 0) {
          disable_pic_dac(local_9);
        }
        local_9 = local_9 + 1;
      }
      set_PWM(100);
      munmap(axi_fpga_addr,0x160);
      close(__fd);
      uVar1 = 0;
    }
  }
  return uVar1;
}

