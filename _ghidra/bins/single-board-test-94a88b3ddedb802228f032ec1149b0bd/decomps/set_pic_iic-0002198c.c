
uint set_pic_iic(uint param_1)

{
  uint uVar1;
  
  *(uint *)(axi_fpga_addr + 0x30) = param_1 & 0x7fffffff;
  while( true ) {
    uVar1 = get_pic_iic();
    if ((int)uVar1 < 0) break;
    usleep(1000);
  }
  return uVar1 & 0xff;
}

