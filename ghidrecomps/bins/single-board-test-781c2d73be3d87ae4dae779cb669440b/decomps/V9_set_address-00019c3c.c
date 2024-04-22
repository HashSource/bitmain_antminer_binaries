
/* WARNING: Unknown calling convention */

void V9_set_address(uchar which_chain)

{
  char cVar1;
  uint uVar2;
  
  printf("\n--- %s: Chain : %d\n",DAT_00019c84,(uint)which_chain);
  cVar1 = '-';
  uVar2 = 0;
  BM1385_chain_inactive(which_chain);
  do {
    BM1385_set_address(which_chain,(uchar)uVar2);
    uVar2 = uVar2 + gChain_Asic_Interval;
    usleep(5000);
    cVar1 = cVar1 + -1;
    uVar2 = uVar2 & 0xff;
  } while (cVar1 != '\0');
  return;
}

