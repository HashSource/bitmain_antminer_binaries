
/* WARNING: Unknown calling convention */

void BM1391_set_baud(uchar which_chain,uchar baud)

{
  printf("\n--- %s: Chain : %d, baud = %d\n",DAT_000132dc,(uint)which_chain,(uint)baud);
  gBM1391_MISC_CONTROL_reg = gBM1391_MISC_CONTROL_reg & 0xffffe0ff | (uint)baud << 8;
  BM1391_set_config(which_chain,'\0','\x18',gBM1391_MISC_CONTROL_reg,true);
  usleep(50000);
  set_fpga_baud(baud);
  (*(code *)PTR_usleep_00030148)(50000);
  return;
}

