
void sweep_freq_set_base_freq(working_mode_e working_mode)

{
  int iVar1;
  working_mode_e working_mode_local;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    iVar1 = g_sweep_config_hpf.sweep_min_freq;
    if (working_mode == MODE1) {
      iVar1 = g_sweep_config_eco.sweep_min_freq;
    }
    scanfreq_info.base_freq[chain] = iVar1;
  }
  return;
}

