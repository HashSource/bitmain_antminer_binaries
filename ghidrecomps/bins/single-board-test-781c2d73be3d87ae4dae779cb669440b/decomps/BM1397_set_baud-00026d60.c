
/* WARNING: Unknown calling convention */

void BM1397_set_baud(uchar which_chain,uint baud)

{
  printf("\n--- %s: Chain : %d, baud = %d\n",DAT_00026da0,(uint)which_chain,baud);
  single_BM1397_set_baud(which_chain,'\0',baud,true);
  usleep(50000);
  set_fpga_baud((uchar)baud);
  (*(code *)PTR_usleep_00030148)(50000);
  return;
}

