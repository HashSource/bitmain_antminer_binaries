
void freq_tuning_pre_open_core(freq_tuning_info *freq_info)

{
  freq_tuning_info *freq_info_local;
  int balance_times;
  int i;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      set_reset_hashboard(chain,1);
      sleep(3);
      set_reset_hashboard(chain,0);
      sleep(3);
    }
  }
  set_iic_power_to_highest_voltage();
  for (i = 0; i < 2; i = i + 1) {
    balance_domain_voltage();
  }
  return;
}

