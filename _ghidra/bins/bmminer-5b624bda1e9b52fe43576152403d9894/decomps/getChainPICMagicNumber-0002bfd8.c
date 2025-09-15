
/* WARNING: Unknown calling convention */

int getChainPICMagicNumber(int chainIndex)

{
  int iVar1;
  
  if (fpga_version < 0xe) {
    return (uint)chain_pic_buf[(chainIndex / 3) * 3][0];
  }
  if (chainIndex - 1U < 0xd) {
    iVar1 = *(int *)(CSWTCH_824 + (chainIndex - 1U) * 4);
  }
  else {
    iVar1 = 0;
  }
  return (uint)chain_pic_buf[iVar1][0];
}

