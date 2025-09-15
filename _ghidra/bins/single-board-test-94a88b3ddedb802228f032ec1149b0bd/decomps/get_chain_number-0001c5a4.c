
int get_chain_number(int param_1)

{
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  do {
    if (0xf < local_10) {
      return -1;
    }
    if (*(int *)(cgpu + (local_10 + 0x9c638) * 4) != 0) {
      if (local_10 == param_1) {
        return local_c;
      }
      local_c = local_c + 1;
    }
    local_10 = local_10 + 1;
  } while( true );
}

