
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reset_hash_board(void)

{
  printf("--- %s\n","reset_hash_board");
  axi_fpga_addr[0xd] = 0xffff;
  usleep(500000);
  axi_fpga_addr[0xd] = 0;
  return;
}

