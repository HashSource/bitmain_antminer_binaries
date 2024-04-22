
_Bool eeprom_get_freq(uint8_t chain,uint32_t *buf)

{
  byte bVar1;
  _Bool _Var2;
  uint32_t *buf_local;
  uint8_t chain_local;
  int i;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    _Var2 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    usleep(10000);
    for (i = 0; i < 0x6c; i = i + 1) {
      bVar1 = eeprom_read_one_byte((char)i + '\x02',chain);
      buf[i] = bVar1 + 200;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var2 = eeprom_check_crc(chain);
  }
  return _Var2;
}

