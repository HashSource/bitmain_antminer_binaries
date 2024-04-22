
void freq_tuning_adjust_result_according_to_distance_to_air_in
               (freq_tuning_info *freq_info,int chain)

{
  int iVar1;
  int iVar2;
  int chain_local;
  freq_tuning_info *freq_info_local;
  int freq_diff;
  int distance;
  int column;
  int column_air_in;
  int asic;
  
  iVar1 = get_logical_column_by_chip_no(0xb);
  for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
    iVar2 = get_logical_column_by_chip_no(asic);
    iVar2 = iVar2 - iVar1;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    freq_info->freq_table[chain][asic] = freq_info->freq_table[chain][asic] + (iVar2 / 2) * -10;
  }
  return;
}

