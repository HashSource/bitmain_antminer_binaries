
_Bool chainHasDisabledCore(int chainIndex)

{
  int chainIndex_local;
  int j;
  
  if ((disabledcore_pos_buf[chainIndex][0] == ',') && (disabledcore_pos_buf[chainIndex][1] == 'e'))
  {
    for (j = 1; j < 8; j = j + 1) {
      if ((disabledcore_pos_buf[chainIndex][j * 2] < 0x6c) &&
         (disabledcore_pos_buf[chainIndex][j * 2 + 1] < 0xd0)) {
        return true;
      }
    }
  }
  return false;
}

