
_Bool check_freq_valid_single(uint32_t freq,uint32_t valid_max_freq)

{
  undefined uVar1;
  uint32_t uVar2;
  uint32_t valid_max_freq_local;
  uint32_t freq_local;
  
  uVar2 = valid_max_freq;
  if (freq <= valid_max_freq) {
    uVar2 = 1;
  }
  uVar1 = (undefined)uVar2;
  if (valid_max_freq < freq) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

