
/* WARNING: Unknown calling convention */

int do_get_ideal_max_hash_rate(void)

{
  _Bool _Var1;
  uint32_t *buf;
  uint32_t *freq_one_chain;
  int i;
  int chain;
  uint32_t total_rate;
  
  buf = (uint32_t *)malloc(0xf0);
  total_rate = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      _Var1 = is_economic_mode();
      if (_Var1) {
        eeprom_get_freq_mode1((uint8_t)chain,buf);
      }
      else {
        eeprom_get_freq_mode2((uint8_t)chain,buf);
      }
      for (i = 0; i < 0x3c; i = i + 1) {
        total_rate = buf[i] * 0xd0 + total_rate;
      }
    }
  }
  if (buf != (uint32_t *)0x0) {
    free(buf);
  }
  return total_rate / 1000;
}

