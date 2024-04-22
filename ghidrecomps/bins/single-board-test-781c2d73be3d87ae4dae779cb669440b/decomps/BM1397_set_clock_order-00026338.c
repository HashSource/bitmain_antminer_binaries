
/* WARNING: Unknown calling convention */

void BM1397_set_clock_order(uchar which_chain,uchar chip_addr,_Bool mode)

{
  printf("chain[%d]: set order clock, stragegy 3\n",(uint)which_chain);
  BM1397_set_config(which_chain,chip_addr,0x80,0,mode);
  BM1397_set_config(which_chain,chip_addr,0x84,0,mode);
  usleep(100000);
  BM1397_set_config(which_chain,chip_addr,' ',1,mode);
  return;
}

