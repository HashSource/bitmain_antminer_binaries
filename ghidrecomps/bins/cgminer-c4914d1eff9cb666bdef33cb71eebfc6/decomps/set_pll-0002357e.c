
void set_pll(float pll_value)

{
  float pll_value_local;
  int local_pll_index;
  uint8_t chain;
  
  local_pll_index = 0;
  if (opt_use_pll_list) {
    local_pll_index = get_index_from_high_pll((int)pll_value);
  }
  for (chain = '\0'; chain < 0x10; chain = chain + '\x01') {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      change_high_pll_test(chain,pll_value,local_pll_index);
    }
  }
  return;
}

