
uchar set_iic(uint data)

{
  uint uVar1;
  uint data_local;
  int wait_counter;
  uchar ret_data;
  uint ret;
  
  axi_fpga_addr[0xc] = data & 0x7fffffff;
  while( true ) {
    uVar1 = get_iic();
    if ((int)uVar1 < 0) break;
    usleep(1000);
  }
  return (uchar)uVar1;
}

