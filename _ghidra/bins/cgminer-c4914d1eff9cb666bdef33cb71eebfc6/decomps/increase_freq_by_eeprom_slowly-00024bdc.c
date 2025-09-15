
uint16_t increase_freq_by_eeprom_slowly(int init_freq,int freq_step)

{
  uint16_t uVar1;
  int freq_step_local;
  int init_freq_local;
  
  uVar1 = increase_freq_by_eeprom_slowly_new(init_freq,freq_step);
  return uVar1;
}

