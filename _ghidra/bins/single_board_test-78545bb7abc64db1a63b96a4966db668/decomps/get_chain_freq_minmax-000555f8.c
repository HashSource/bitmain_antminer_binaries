
int32_t get_chain_freq_minmax(_Bool is_max,eeprom_v1 *ctx,int num)

{
  int num_local;
  eeprom_v1 *ctx_local;
  _Bool is_max_local;
  sweep_result_t sr;
  int i;
  int asic;
  int32_t freq;
  
  memset(&sr,0,0x40c);
  eeprom_get_sweep_result(&sr,ctx);
  freq = sr.freqs[0];
  for (asic = 0; asic < num; asic = asic + 1) {
    if ((!is_max) && (sr.freqs[asic] < (uint)freq)) {
      freq = sr.freqs[asic];
    }
    if ((is_max) && ((uint)freq < sr.freqs[asic])) {
      freq = sr.freqs[asic];
    }
  }
  return freq;
}

