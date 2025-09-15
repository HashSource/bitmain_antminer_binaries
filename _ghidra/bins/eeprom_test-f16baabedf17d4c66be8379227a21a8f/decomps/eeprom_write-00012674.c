
_Bool eeprom_write(uint8_t chain,uint32_t addr,uint8_t *buf,uint32_t len)

{
  _Bool _Var1;
  uint32_t len_local;
  uint8_t *buf_local;
  uint32_t addr_local;
  uint8_t chain_local;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    _Var1 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    eeprom_write_bytes((uint8_t)addr,buf,chain,(uint8_t)len);
    usleep(10000);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var1 = eeprom_update_crc(chain);
  }
  return _Var1;
}

