
/* WARNING: Unknown calling convention */

int getChainAsicFreqIndex(int chainIndex,int asicIndex)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if (fpga_version < 0xe) {
    bVar1 = *(byte *)((int)chain_pic_buf +
                     chainIndex * 0x1f + (chainIndex / 3) * 0x123 + asicIndex + 0xb);
  }
  else {
    if (chainIndex - 1U < 0xd) {
      iVar3 = (chainIndex - 1U) * 4;
      iVar2 = *(int *)(CSWTCH_824 + iVar3);
      iVar3 = *(int *)(CSWTCH_825 + iVar3) * 0x1f + 0xb;
    }
    else {
      iVar2 = 0;
      iVar3 = 0xb;
    }
    bVar1 = chain_pic_buf[iVar2][asicIndex + iVar3];
  }
  return (uint)bVar1;
}

