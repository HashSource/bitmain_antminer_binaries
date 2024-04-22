
_Bool eeprom_set_inbalance_info(uint8_t chain,uint8_t *buf,uint32_t len)

{
  _Bool _Var1;
  uint32_t len_local;
  uint8_t *buf_local;
  uint8_t chain_local;
  
  if (len < 7) {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    if (chain_list[chain] != 0) {
      eeprom_write_one_byte('r',(uint8_t)len,chain);
      eeprom_write_bytes('s',buf,chain,(uint8_t)len);
    }
    usleep(10000);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var1 = eeprom_update_crc(chain);
  }
  else {
    printf("error: inbalance data are more than %d\n",6);
    _Var1 = false;
  }
  return _Var1;
}

