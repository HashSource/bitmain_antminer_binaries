
/* WARNING: Unknown calling convention */

void BHB91603_set_address(uchar which_chain)

{
  uint uVar1;
  uint uVar2;
  
  printf("\n--- %s: Chain : %d\n",DAT_00016ddc,(uint)which_chain);
  BM1391_chain_inactive(which_chain);
  if (BHB91603_ASIC_NUMBER != 0) {
    uVar1 = 0;
    uVar2 = 0;
    do {
      BM1391_set_address(which_chain,(uchar)uVar2);
      uVar1 = uVar1 + 1 & 0xff;
      uVar2 = uVar2 + gChain_Asic_Interval;
      usleep(5000);
      uVar2 = uVar2 & 0xff;
    } while (uVar1 < BHB91603_ASIC_NUMBER);
  }
  return;
}

