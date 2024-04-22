
_Bool eeprom_get_inbalance_info(uint8_t chain,uint8_t *buf,uint32_t *len)

{
  byte length;
  _Bool _Var1;
  uint32_t *len_local;
  uint8_t *buf_local;
  uint8_t chain_local;
  uint8_t inbalance_num;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist\n",(uint)chain);
    _Var1 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    length = eeprom_read_one_byte('r',chain);
    *len = (uint)length;
    eeprom_write_bytes('s',buf,chain,length);
    usleep(10000);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var1 = eeprom_check_crc(chain);
  }
  return _Var1;
}

