
_Bool isDisabledCore(int chainIndex,int chipIndex,int coreIndex)

{
  int coreIndex_local;
  int chipIndex_local;
  int chainIndex_local;
  int i;
  
  if ((disabledcore_pos_buf[chainIndex][0] == ',') && (disabledcore_pos_buf[chainIndex][1] == 'e'))
  {
    for (i = 1; i < 8; i = i + 1) {
      if (((uint)disabledcore_pos_buf[chainIndex][i * 2] == chipIndex) &&
         ((uint)disabledcore_pos_buf[chainIndex][i * 2 + 1] == coreIndex)) {
        return true;
      }
    }
  }
  return false;
}

