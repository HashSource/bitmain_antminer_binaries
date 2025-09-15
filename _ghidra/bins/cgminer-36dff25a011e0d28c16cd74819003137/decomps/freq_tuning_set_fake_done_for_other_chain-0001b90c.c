
void freq_tuning_set_fake_done_for_other_chain(freq_tuning_info *freq_info,int chain)

{
  int chain_local;
  freq_tuning_info *freq_info_local;
  int chain_other;
  
  for (chain_other = 0; chain_other < 0x10; chain_other = chain_other + 1) {
    if (((dev->chain_exist[chain_other] != 0) && (chain_other != chain)) &&
       (freq_info->test_done[chain_other] != true)) {
      freq_info->fake_done[chain_other] = true;
    }
  }
  return;
}

