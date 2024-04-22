
/* WARNING: Unknown calling convention */

void BHB91601_set_baud(uchar which_chain,uchar baud)

{
  printf("\n--- %s: Chain : %d, baud = %d\n",DAT_0001c1d8,(uint)which_chain,(uint)baud);
  BM1391_set_baud(which_chain,baud);
  usleep(50000);
  set_fpga_baud(baud);
  return;
}

