
undefined4 isBoardFreqTooLow(int param_1)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0x53 < local_c) {
      return 1;
    }
    if (4 < *(byte *)(local_c * 2 + 3 + param_1)) break;
    local_c = local_c + 1;
  }
  return 0;
}

