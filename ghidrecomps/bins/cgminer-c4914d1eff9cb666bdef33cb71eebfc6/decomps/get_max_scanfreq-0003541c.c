
float get_max_scanfreq(_Bool is_economic_mode)

{
  int iVar1;
  _Bool is_economic_mode_local;
  
  iVar1 = g_sweep_config_hpf.sweep_max_freq;
  if (is_economic_mode) {
    iVar1 = g_sweep_config_eco.sweep_max_freq;
  }
  return (float)(longlong)iVar1;
}

