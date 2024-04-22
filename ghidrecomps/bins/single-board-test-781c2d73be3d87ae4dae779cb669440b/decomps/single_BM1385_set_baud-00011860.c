
/* WARNING: Unknown calling convention */

void single_BM1385_set_baud(uchar which_chain,uchar baud)

{
  printf("\n--- %s: Chain : %d, baud = %d\n",DAT_00011898,(uint)which_chain,(uint)baud);
  BM1385_set_baud(which_chain,'\0',baud,true);
  usleep(50000);
  set_fpga_baud(baud);
  return;
}

