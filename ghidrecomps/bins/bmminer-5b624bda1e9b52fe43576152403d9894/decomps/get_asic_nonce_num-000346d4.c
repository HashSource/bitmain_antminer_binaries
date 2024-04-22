
/* WARNING: Unknown calling convention */

int get_asic_nonce_num(int chain,int asic,int timeslice)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (timeslice < 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    iVar3 = *(int *)(DAT_00034734 + 0x678) % 0x3c + -1;
    iVar4 = iVar3 - timeslice;
    do {
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = iVar3 + 0x3c;
      }
      iVar3 = iVar3 + -1;
      iVar1 = iVar1 + *(int *)(DAT_00034734 + 0x680 + (chain * 0xf00 + asic * 0x3c + iVar2) * 8);
    } while (iVar3 != iVar4);
  }
  return iVar1;
}

