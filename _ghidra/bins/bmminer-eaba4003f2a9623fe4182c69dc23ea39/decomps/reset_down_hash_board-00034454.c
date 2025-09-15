
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reset_down_hash_board(void)

{
  printf("--- %s\n","reset_down_hash_board");
  axi_fpga_addr[0xd] = 0xffff;
  return;
}

