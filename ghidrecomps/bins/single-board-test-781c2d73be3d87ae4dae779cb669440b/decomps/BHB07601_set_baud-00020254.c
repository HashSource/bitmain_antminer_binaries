
/* WARNING: Unknown calling convention */

void BHB07601_set_baud(uchar which_chain,uchar baud)

{
  printf("\n--- %s: Chain : %d, baud = %d\n",DAT_00020278,(uint)which_chain,(uint)baud);
  BM1397_set_baud(which_chain,(uint)baud);
  return;
}

