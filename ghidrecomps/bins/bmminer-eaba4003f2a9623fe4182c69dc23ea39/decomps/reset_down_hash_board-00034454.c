
/* WARNING: Unknown calling convention */

void reset_down_hash_board(void)

{
  printf("--- %s\n","reset_down_hash_board");
  axi_fpga_addr[0xd] = 0xffff;
  return;
}

