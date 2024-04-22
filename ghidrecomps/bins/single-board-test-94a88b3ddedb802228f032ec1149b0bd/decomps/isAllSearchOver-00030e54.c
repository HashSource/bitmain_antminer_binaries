
undefined4 isAllSearchOver(void)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0xf < local_c) {
      return 1;
    }
    if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) && (search_over[local_c] != '\x01')) break;
    local_c = local_c + 1;
  }
  return 0;
}

