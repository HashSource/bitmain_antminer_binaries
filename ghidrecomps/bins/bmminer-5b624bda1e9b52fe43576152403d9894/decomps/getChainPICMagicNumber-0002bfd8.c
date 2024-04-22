
/* WARNING: Unknown calling convention */

int getChainPICMagicNumber(int chainIndex)

{
  int new_T9_PLUS_chainIndex;
  
  if (0xd < *DAT_0002c020) {
    if (chainIndex - 1U < 0xd) {
      new_T9_PLUS_chainIndex = *(int *)(DAT_0002c024 + (chainIndex - 1U) * 4 + 0x9b8);
    }
    else {
      new_T9_PLUS_chainIndex = 0;
    }
    return (uint)*(byte *)(DAT_0002c028 + new_T9_PLUS_chainIndex * 0x80 + 0xd4);
  }
  return (uint)*(byte *)(DAT_0002c028 + (chainIndex / 3) * 0x180 + 0xd4);
}

