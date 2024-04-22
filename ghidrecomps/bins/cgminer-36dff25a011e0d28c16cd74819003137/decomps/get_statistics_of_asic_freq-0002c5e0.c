
void get_statistics_of_asic_freq(uint32_t *asic_freq,uint32_t *min,uint32_t *max,uint32_t *total)

{
  uint32_t *total_local;
  uint32_t *max_local;
  uint32_t *min_local;
  uint32_t *asic_freq_local;
  uint32_t _total;
  uint32_t _max;
  uint32_t _min;
  int asic;
  
  _min = 0xffffff;
  _max = 0;
  _total = 0;
  for (asic = 0; asic < 0x30; asic = asic + 1) {
    if (_max < asic_freq[asic]) {
      _max = asic_freq[asic];
    }
    if (asic_freq[asic] < _min) {
      _min = asic_freq[asic];
    }
    _total = _total + asic_freq[asic];
  }
  *min = _min;
  *max = _max;
  *total = _total;
  return;
}

