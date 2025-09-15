
uint set_iic(uint param_1)

{
  uint uVar1;
  int local_c;
  
  local_c = 0;
  *(uint *)(axi_fpga_addr + 0x30) = param_1 & 0x3fffffff;
  while( true ) {
    uVar1 = get_iic();
    if ((int)uVar1 < 0) {
      return uVar1 & 0xff;
    }
    if (100 < local_c) break;
    usleep(5000);
    local_c = local_c + 1;
  }
  printf("could not get iic, ret = 0x%08x\n",uVar1);
  return 0;
}

