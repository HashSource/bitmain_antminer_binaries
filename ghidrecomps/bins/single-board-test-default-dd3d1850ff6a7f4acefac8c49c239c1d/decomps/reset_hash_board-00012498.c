
void reset_hash_board(void)

{
  write_axi_fpga(0xd,0xffff);
  usleep(300000);
  write_axi_fpga(0xd,0);
  usleep(300000);
  return;
}

