
/* WARNING: Unknown calling convention */

void BM1391_software_set_address(uchar which_chain)

{
  uint uVar1;
  int iVar2;
  
  printf("\n--- %s: Chain : %d\n",DAT_0001327c,(uint)which_chain);
  BM1391_chain_inactive(which_chain);
  if (BHB91601_ASIC_NUMBER != 0) {
    uVar1 = 0;
    iVar2 = 0;
    do {
      uVar1 = uVar1 + 1;
      BM1391_set_address(which_chain,(uchar)iVar2);
      usleep(2000);
      iVar2 = iVar2 + gChain_Asic_Interval;
    } while (uVar1 < BHB91601_ASIC_NUMBER);
  }
  return;
}

