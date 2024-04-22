
int getChainAsicFreqIndex(int chainIndex,int asicIndex)

{
  int asicIndex_local;
  int chainIndex_local;
  
  return (uint)last_freq[chainIndex][asicIndex * 2 + 3];
}

