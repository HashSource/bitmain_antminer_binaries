
char target_to_dcrdiff(int param_1)

{
  uint local_14;
  int local_10;
  char local_9;
  
  local_9 = '\0';
  local_10 = 7;
  do {
    if (local_10 < 0) {
      return local_9;
    }
    for (local_14 = 0x1f; -1 < (int)local_14; local_14 = local_14 - 1) {
      if ((*(uint *)(param_1 + local_10 * 4) >> (local_14 & 0xff) & 1) != 0) {
        return local_9;
      }
      local_9 = local_9 + '\x01';
    }
    local_10 = local_10 + -1;
  } while( true );
}

