
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reset_fpga_and_hash_board(void)

{
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  return;
}

