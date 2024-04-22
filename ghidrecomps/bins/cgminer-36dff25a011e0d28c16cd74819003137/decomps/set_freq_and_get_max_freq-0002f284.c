
/* WARNING: Unknown calling convention */

float set_freq_and_get_max_freq(void)

{
  uint16_t uVar1;
  float max_freq;
  
  if (freq_mode == 2) {
    max_freq = set_target_freq();
  }
  else {
    uVar1 = increase_freq_by_eeprom_slowly((int)init_freq,(int)freq_step);
    max_freq = (float)(ulonglong)uVar1;
  }
  return max_freq;
}

