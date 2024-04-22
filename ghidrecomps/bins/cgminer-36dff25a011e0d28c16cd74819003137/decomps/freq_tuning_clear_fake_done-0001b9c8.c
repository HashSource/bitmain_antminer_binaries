
void freq_tuning_clear_fake_done(freq_tuning_info *freq_info)

{
  freq_tuning_info *freq_info_local;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      freq_info->fake_done[chain] = false;
    }
  }
  return;
}

