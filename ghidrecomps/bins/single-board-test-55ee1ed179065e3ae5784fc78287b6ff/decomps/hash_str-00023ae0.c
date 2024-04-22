
int hash_str(byte *param_1)

{
  int local_10;
  byte *local_c;
  
  local_10 = 0x1505;
  for (local_c = param_1; *local_c != 0; local_c = local_c + 1) {
    local_10 = local_10 * 0x21 + (uint)*local_c;
  }
  return local_10;
}

