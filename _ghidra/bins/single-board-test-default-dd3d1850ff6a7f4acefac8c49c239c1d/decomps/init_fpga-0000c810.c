
void init_fpga(void)

{
  int iVar1;
  
  printf("\n--- %s\n","init_fpga");
  write_axi_fpga(0x20,0x80008000);
  while (iVar1 = read_axi_fpga(0x20), iVar1 < 0) {
    usleep(10000);
  }
  usleep(100000);
  return;
}

