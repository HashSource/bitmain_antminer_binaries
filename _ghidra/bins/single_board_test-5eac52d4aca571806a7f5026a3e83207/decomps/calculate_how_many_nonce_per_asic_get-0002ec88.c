
uint32_t calculate_how_many_nonce_per_asic_get(uint8_t which_asic,uint32_t core_number)

{
  uint32_t core_number_local;
  uint8_t which_asic_local;
  uint32_t which_core;
  uint32_t ret;
  
  ret = 0;
  for (which_core = 0; which_core < core_number; which_core = which_core + 1) {
    ret = ret + gHistory_Result[gPattern_test_counter].asic_core_nonce_num[which_asic][which_core];
  }
  return ret;
}

