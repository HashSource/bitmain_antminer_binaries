
_Bool eeprom_set_freq_one_chain(uint8_t chain,uint8_t *buf,uint8_t buf_len)

{
  _Bool _Var1;
  uint8_t *buf_local;
  uint8_t buf_len_local;
  uint8_t chain_local;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    _Var1 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    usleep(10000);
    eeprom_write_one_byte('\0','}',chain);
    eeprom_write_bytes('\x02',buf,chain,buf_len);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var1 = eeprom_update_crc(chain);
  }
  return _Var1;
}

