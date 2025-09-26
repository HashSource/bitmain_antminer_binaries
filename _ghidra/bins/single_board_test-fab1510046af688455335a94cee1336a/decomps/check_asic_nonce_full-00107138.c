
_Bool check_asic_nonce_full(int *times)

{
  int *times_local;
  int i;
  
  i = 0x70;
  while( true ) {
    if ((Local_Config_Information->Hash_Board).Big_Core_Num <= (uint)i) {
      return true;
    }
    if (g_asic_unique_nonce[i].count == 0) break;
    i = i + 1;
  }
  g_asic_unique_nonce[i].times = g_asic_unique_nonce[i].times + 1;
  *times = g_asic_unique_nonce[i].times;
  if (100 < g_asic_unique_nonce[i].times) {
    g_asic_unique_nonce[i].times = 0;
  }
  return false;
}

