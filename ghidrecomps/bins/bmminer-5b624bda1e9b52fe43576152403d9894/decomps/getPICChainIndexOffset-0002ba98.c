
/* WARNING: Unknown calling convention */

void getPICChainIndexOffset(int chainIndex,int *pChain,int *pOffset)

{
  int new_T9_PLUS_chainOffset;
  int iVar1;
  int new_T9_PLUS_chainIndex;
  int iVar2;
  
  if (chainIndex - 1U < 0xd) {
    iVar1 = (chainIndex - 1U) * 4;
    iVar2 = *(int *)(CSWTCH_824 + iVar1);
    iVar1 = *(int *)(CSWTCH_825 + iVar1);
  }
  else {
    iVar1 = 0;
    iVar2 = iVar1;
  }
  *pChain = iVar2;
  *pOffset = iVar1;
  return;
}

