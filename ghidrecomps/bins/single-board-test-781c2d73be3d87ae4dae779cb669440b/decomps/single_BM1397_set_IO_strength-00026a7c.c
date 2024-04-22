
/* WARNING: Unknown calling convention */

void single_BM1397_set_IO_strength(uchar which_chain,uchar chip_addr,uint data,_Bool mode)

{
  printf("\n--- %s: IO strength is 0x%08x\n",DAT_00026aa8);
  BM1397_set_config(which_chain,chip_addr,'X',data,mode);
  return;
}

