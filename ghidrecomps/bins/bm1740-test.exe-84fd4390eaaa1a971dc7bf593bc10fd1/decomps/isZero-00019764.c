
undefined4 isZero(int param_1,uint param_2)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (param_2 <= local_c) {
      return 1;
    }
    if (*(char *)(param_1 + local_c) != '\0') break;
    local_c = local_c + 1;
  }
  return 0;
}

