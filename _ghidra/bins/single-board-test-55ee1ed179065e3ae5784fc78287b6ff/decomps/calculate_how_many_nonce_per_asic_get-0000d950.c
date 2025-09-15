
int calculate_how_many_nonce_per_asic_get(byte param_1,byte param_2,uint param_3)

{
  uint local_10;
  int local_c;
  
  local_c = 0;
  for (local_10 = 0; local_10 < param_3; local_10 = local_10 + 1) {
    local_c = local_c + *(int *)(gAsic_Core_Nonce_Num +
                                (((uint)param_1 * 0x100 + (uint)param_2) * 0x200 + local_10) * 4);
  }
  return local_c;
}

