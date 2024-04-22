
/* WARNING: Unknown calling convention */

void reset_hash_board(void)

{
  write_axi_fpga(0xd,0xffff);
  usleep(300000);
  write_axi_fpga(0xd,0);
  (*(code *)PTR_usleep_00030148)(300000);
  return;
}

