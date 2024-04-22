
/* WARNING: Unknown calling convention */

void single_BM1385_set_address(uchar which_chain)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  printf("\n--- %s: Chain : %d\n",DAT_0001185c,(uint)which_chain);
  BM1385_chain_inactive(which_chain);
  iVar1 = __udivsi3(0x100,gChain_Asic_Interval);
  if (iVar1 != 0) {
    uVar3 = 0;
    iVar1 = 0;
    do {
      uVar3 = uVar3 + 1;
      BM1385_set_address(which_chain,(uchar)iVar1);
      iVar1 = iVar1 + gChain_Asic_Interval;
      usleep(5000);
      uVar2 = __udivsi3(0x100,gChain_Asic_Interval);
    } while (uVar3 < uVar2);
  }
  return;
}

