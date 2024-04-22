
uint32_t get_vol_region_nonce_number(uint32_t chain,uint32_t vol_region)

{
  uint32_t vol_region_local;
  uint32_t chain_local;
  uint32_t tmp;
  uint32_t core;
  uint32_t asic;
  uint32_t nonce_number;
  
  nonce_number = 0;
  for (asic = vol_region * 10; asic < (vol_region + 1) * 10; asic = asic + 1) {
    tmp = 0;
    for (core = 0; core < 0xd0; core = core + 1) {
      tmp = tmp + scanfreq_calc_nonce_info.chain_asic_core_nonce_num[chain][asic][core];
    }
    nonce_number = tmp + nonce_number;
  }
  return nonce_number;
}

