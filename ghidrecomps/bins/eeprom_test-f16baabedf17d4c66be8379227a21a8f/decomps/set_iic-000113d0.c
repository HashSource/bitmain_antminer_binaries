
uchar set_iic(uint data)

{
  uint uVar1;
  uint data_local;
  uchar ret_data;
  uint ret;
  int wait_counter;
  
  wait_counter = 0;
  axi_fpga_addr[0xc] = data & 0x3fffffff;
  while( true ) {
    uVar1 = get_iic();
    if ((int)uVar1 < 0) {
      return (uchar)uVar1;
    }
    if (100 < wait_counter) break;
    usleep(5000);
    wait_counter = wait_counter + 1;
  }
  printf("could not get iic, ret = 0x%08x\n",uVar1);
  return '\0';
}

