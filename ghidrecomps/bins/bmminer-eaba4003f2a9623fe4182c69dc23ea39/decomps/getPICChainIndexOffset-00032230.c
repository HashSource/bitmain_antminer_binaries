
void getPICChainIndexOffset(int chainIndex,int *pChain,int *pOffset)

{
  int *pOffset_local;
  int *pChain_local;
  int chainIndex_local;
  int new_T9_PLUS_chainOffset;
  int new_T9_PLUS_chainIndex;
  
  switch(chainIndex) {
  case 1:
    new_T9_PLUS_chainIndex = 1;
    new_T9_PLUS_chainOffset = 0;
    break;
  case 2:
    new_T9_PLUS_chainIndex = 2;
    new_T9_PLUS_chainOffset = 0;
    break;
  case 3:
    new_T9_PLUS_chainIndex = 3;
    new_T9_PLUS_chainOffset = 0;
    break;
  default:
    new_T9_PLUS_chainIndex = 0;
    new_T9_PLUS_chainOffset = 0;
    break;
  case 8:
    new_T9_PLUS_chainIndex = 1;
    new_T9_PLUS_chainOffset = 1;
    break;
  case 9:
    new_T9_PLUS_chainIndex = 1;
    new_T9_PLUS_chainOffset = 2;
    break;
  case 10:
    new_T9_PLUS_chainIndex = 2;
    new_T9_PLUS_chainOffset = 1;
    break;
  case 0xb:
    new_T9_PLUS_chainIndex = 2;
    new_T9_PLUS_chainOffset = 2;
    break;
  case 0xc:
    new_T9_PLUS_chainIndex = 3;
    new_T9_PLUS_chainOffset = 1;
    break;
  case 0xd:
    new_T9_PLUS_chainIndex = 3;
    new_T9_PLUS_chainOffset = 2;
  }
  *pChain = new_T9_PLUS_chainIndex;
  *pOffset = new_T9_PLUS_chainOffset;
  return;
}

